#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> vector<T> operator-(vector<T> a) {
  for (auto&& e : a) e = -e;
  return a;
}
template <class T> vector<T>& operator+=(vector<T>& a, const vector<T>& b) {
  a.resize(max(a.size(), b.size()));
  for (int i = 0; i < (int)b.size(); ++i) a[i] += b[i];
  return a;
}
template <class T> vector<T> operator+(vector<T> a, const vector<T>& b) {
  return a += b;
}
template <class T> vector<T>& operator-=(vector<T>& a, const vector<T>& b) {
  a.resize(max(a.size(), b.size()));
  for (int i = 0; i < (int)b.size(); ++i) a[i] -= b[i];
  return a;
}
template <class T> vector<T> operator-(vector<T> a, const vector<T>& b) {
  return a -= b;
}
template <class T> vector<T>& operator<<=(vector<T>& a, size_t n) {
  return a.insert(begin(a), n, 0), a;
}
template <class T> vector<T> operator<<(vector<T> a, size_t n) {
  return a <<= n;
}
template <class T> vector<T>& operator>>=(vector<T>& a, size_t n) {
  return a.erase(begin(a), begin(a) + min(a.size(), n)), a;
}
template <class T> vector<T> operator>>(vector<T> a, size_t n) {
  return a >>= n;
}
template <class T> vector<T> operator*(const vector<T>& a, const vector<T>& b) {
  if (a.empty() or b.empty()) return {};
  vector<T> res(a.size() + b.size() - 1);
  for (int i = 0; i < (int)a.size(); ++i)
    for (int j = 0; j < (int)b.size(); ++j) res[i + j] += a[i] * b[j];
  return res;
}
template <class T> vector<T>& operator*=(vector<T>& a, const vector<T>& b) {
  return a = a * b;
}
template <class T> vector<T> inverse(const vector<T>& a) {
  assert(not a.empty() and not (a[0] == 0));
  vector<T> b{1 / a[0]};
  while (b.size() < a.size()) {
    vector<T> x(begin(a), begin(a) + min(a.size(), 2 * b.size()));
    x *= b * b;
    b.resize(2 * b.size());
    for (auto i = b.size() / 2; i < min(x.size(), b.size()); ++i) b[i] = -x[i];
  }
  return {begin(b), begin(b) + a.size()};
}
template <class T> vector<T> operator/(vector<T> a, vector<T> b) {
  if (a.size() < b.size()) return {};
  reverse(begin(a), end(a)), reverse(begin(b), end(b));
  int n = a.size() - b.size() + 1;
  a.resize(n), b.resize(n);
  a *= inverse(b);
  return {rend(a) - n, rend(a)};
}
template <class T> vector<T>& operator/=(vector<T>& a, const vector<T>& b) {
  return a = a / b;
}
template <class T> vector<T> operator%(vector<T> a, const vector<T>& b) {
  if (a.size() < b.size()) return a;
  a -= a / b * b;
  return {begin(a), begin(a) + (b.size() - 1)};
}
template <class T> vector<T>& operator%=(vector<T>& a, const vector<T>& b) {
  return a = a % b;
}
template <class T> vector<T> derivative(const vector<T>& a) {
  vector<T> res(max((int)a.size() - 1, 0));
  for (int i = 0; i < (int)res.size(); ++i) res[i] = (i + 1) * a[i + 1];
  return res;
}
template <class T> vector<T> primitive(const vector<T>& a) {
  vector<T> res(a.size() + 1);
  for (int i = 1; i < (int)res.size(); ++i) res[i] = a[i - 1] / i;
  return res;
}
template <class T> vector<T> logarithm(const vector<T>& a) {
  assert(not a.empty() and a[0] == 1);
  auto res = primitive(derivative(a) * inverse(a));
  return {begin(res), begin(res) + a.size()};
}
template <class T> vector<T> exponent(const vector<T>& a) {
  assert(a.empty() or a[0] == 0);
  vector<T> b{1};
  while (b.size() < a.size()) {
    vector<T> x(begin(a), begin(a) + min(a.size(), 2 * b.size()));
    x[0] += 1;
    b.resize(2 * b.size());
    x -= logarithm(b);
    x *= {begin(b), begin(b) + b.size() / 2};
    for (auto i = b.size() / 2; i < min(x.size(), b.size()); ++i) b[i] = x[i];
  }
  return {begin(b), begin(b) + a.size()};
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a{1}, b;
  while (n--) {
    auto na = (a << 1) + b;
    auto nb = a;
    swap(a, na);
    swap(b, nb);
  }
  DEBUG(a);
  DEBUG(b);
  for (int _ = 2; _--; ) {
    cout << a.size() - 1 << '\n';
    for (int i = 0; i < (int)size(a); ++i) {
      cout << (a[i] & 1) << " \n"[i == (int)size(a) - 1];
    }
    a = b;
  }
}