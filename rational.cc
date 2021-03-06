/* Xiao Lin
 * Implementation of rational number type
 * CSE 374 HW7, 17wi
 */

#include "rational.h"
#include <algorithm>
using namespace std;

// FUNCTION PROTORYPES
// Simplifies a fraction to have the lowest factored terms
int simplify(int n, int d);

// constructors:

// Construct Rational 0/1
Rational::Rational() {
  num = 0;
  denom = 1;
}

// Construct Rational n/1
Rational::Rational(int n) {
  num = n;
  denom = 1;
}

// Construct Rational n/d
Rational::Rational(int n, int d) {
  int gcd = simplify(n, d);

  n /= gcd;
  d /= gcd;

  // denominator should always be non-negative
  if (d < 0) {
    n *= -1;
    d *= -1;
  }

  num = n;
  denom = d;
}

// member functions that do not modify this are marked as const to
// document that they only read this but do not change it.

// accessors: return the numerator and denominator of this Rational.
// Results are in lowest terms (i.e., for rational r, r.n() and r.d()
// have no common integer divisors greater than 1).
int Rational::n() const {
  return num;
}

int Rational::d() const {
  return denom;
}

// arithmetic: return a new Rational that results from combining
// this Rational with another.  Neither operand is changed.

// = this + other
Rational Rational::plus(Rational other) const {
  int thisDenom = this->d();
  int thisNum = this->n();
  int otherDenom = other.d();
  int otherNum = other.n();

  int finalNumerator = thisNum * otherDenom + otherNum * thisDenom;
  int finalDenom = thisDenom * otherDenom;

  Rational result = Rational(finalNumerator, finalDenom);

  return result;
}

// = this - other
Rational Rational::minus(Rational other) const {
  int thisDenom = this->d();
  int thisNum = this->n();
  int otherDenom = other.d();
  int otherNum = other.n();

  int finalNumerator = thisNum * otherDenom - otherNum * thisDenom;
  int finalDenom = thisDenom * otherDenom;

  Rational result = Rational(finalNumerator, finalDenom);

  return result;
}

// = this * other
Rational Rational::times(Rational other) const {
  int thisDenom = this->d();
  int thisNum = this->n();
  int otherDenom = other.d();
  int otherNum = other.n();

  int finalNumerator = thisNum * otherNum;
  int finalDenom = thisDenom * otherDenom;

  Rational result = Rational(finalNumerator, finalDenom);

  return result;
}

// = this / other
Rational Rational::div(Rational other) const {
  int thisDenom = this->d();
  int thisNum = this->n();
  int otherDenom = other.d();
  int otherNum = other.n();

  int finalNumerator = thisNum * otherDenom;
  int finalDenom = thisDenom * otherNum;

  Rational result = Rational(finalNumerator, finalDenom);

  return result;
}

int simplify(int n, int d) {
  int gcd = d == 0 ? 1 : __gcd(n, d);
  return gcd;
}
