#include <bits/stdc++.h>

using namespace std;

const int base = 1000000000;
const int base_digits = 9;

struct bigint {
  vector<int> z;
  int sign;

  bigint() : sign(1) {}

  bigint(long long v) {
    *this = v;
  }

  bigint(const string &s) {
    read(s);
  }

  void operator=(const bigint &v) {
    sign = v.sign;
    z = v.z;
  }

  void operator=(long long v) {
    sign = 1;
    if (v < 0) {
      sign = -1, v = -v;
    }
    z.clear();
    for (; v > 0; v = v / base) {
      z.push_back(v % base);
    }
  }

  bigint operator+(const bigint &v) const {
    if (sign == v.sign) {
      bigint res = v;
      for (int i = 0, carry = 0; i < (int) max(z.size(), v.z.size()) || carry; ++i) {
        if (i == (int) res.z.size()) {
          res.z.push_back(0);
        }
        res.z[i] += carry + (i < (int) z.size() ? z[i] : 0);
        carry = res.z[i] >= base;
        if (carry) {
          res.z[i] -= base;
        }
      }
      return res;
    } else {
      return *this - (-v);
    }
  }

  bigint operator-(const bigint &v) const {
    if (sign == v.sign) {
      if (abs() >= v.abs()) {
        bigint res = *this;
        for (int i = 0, carry = 0; i < (int) v.z.size() || carry; ++i) {
          res.z[i] -= carry + (i < (int) v.z.size() ? v.z[i] : 0);
          carry = res.z[i] < 0;
          if (carry) {
            res.z[i] += base;
          }
        }
        res.trim();
        return res;
      } else {
        return -(v - *this);
      }
    } else {
      return *this + (-v);
    }
  }

  void operator*=(int v) {
    if (v < 0) {
      sign = -sign, v = -v;
    }
    for (int i = 0, carry = 0; i < (int) z.size() || carry; ++i) {
      if (i == (int) z.size()) {
        z.push_back(0);
      }
      long long cur = (long long) z[i] * v + carry;
      carry = cur / base;
      z[i] = cur % base;
      // asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
    }
    trim();
  }

  bigint operator*(int v) const {
    bigint res = *this;
    res *= v;
    return res;
  }

  friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
    int norm = base / (b1.z.back() + 1);
    bigint a = a1.abs() * norm;
    bigint b = b1.abs() * norm;
    bigint q, r;
    q.z.resize(a.z.size());
    for (int i = a.z.size() - 1; i >= 0; i--) {
      r *= base;
      r += a.z[i];
      int s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;
      int s2 = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;
      int d = ((long long) s1 * base + s2) / b.z.back();
      r -= b * d;
      while (r < 0) {
        r += b, --d;
      }
      q.z[i] = d;
    }
    q.sign = a1.sign * b1.sign;
    r.sign = a1.sign;
    q.trim();
    r.trim();
    return make_pair(q, r / norm);
  }

  friend bigint sqrt(const bigint &a1) {
    bigint a = a1;
    while (a.z.empty() || (int) a.z.size() % 2 == 1) {
      a.z.push_back(0);
    }
    int n = a.z.size();
    int firstDigit = sqrt((long long) a.z[n - 1] * base + a.z[n - 2]);
    int norm = base / (firstDigit + 1);
    a *= norm;
    a *= norm;
    while (a.z.empty() || (int) a.z.size() % 2 == 1) {
      a.z.push_back(0);
    }
    bigint r = (long long) a.z[n - 1] * base + a.z[n - 2];
    firstDigit = sqrt((long long) a.z[n - 1] * base + a.z[n - 2]);
    int q = firstDigit;
    bigint res;
    for (int j = n / 2 - 1; j >= 0; j--) {
      for (;; --q) {
        bigint r1 =
          (r - (res * 2 * base + q) * q) * base * base +
          (j > 0 ? (long long) a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);
        if (r1 >= 0) {
          r = r1;
          break;
        }
      }
      res *= base;
      res += q;
      if (j > 0) {
        int d1 = res.z.size() + 2 < r.z.size() ? r.z[res.z.size() + 2] : 0;
        int d2 = res.z.size() + 1 < r.z.size() ? r.z[res.z.size() + 1] : 0;
        int d3 = res.z.size() < r.z.size() ? r.z[res.z.size()] : 0;
        q = ((long long) d1 * base * base + (long long) d2 * base + d3) /
            (firstDigit * 2);
      }
    }
    res.trim();
    return res / norm;
  }

  bigint operator/(const bigint &v) const {
    return divmod(*this, v).first;
  }

  bigint operator%(const bigint &v) const {
    return divmod(*this, v).second;
  }

  void operator/=(int v) {
    if (v < 0) {
      sign = -sign, v = -v;
    }
    for (int i = z.size() - 1, rem = 0; i >= 0; --i) {
      long long cur = z[i] + (long long) rem * base;
      z[i] = cur / v;
      rem = cur % v;
    }
    trim();
  }

  bigint operator/(int v) const {
    bigint res = *this;
    res /= v;
    return res;
  }

  int operator%(int v) const {
    if (v < 0) {
      v = -v;
    }
    int m = 0;
    for (int i = z.size() - 1; i >= 0; --i) {
      m = ((long long) m * base + z[i]) % v;
    }
    return m * sign;
  }

  void operator+=(const bigint &v) {
    *this = *this + v;
  }
  void operator-=(const bigint &v) {
    *this = *this - v;
  }
  void operator*=(const bigint &v) {
    *this = *this * v;
  }
  void operator/=(const bigint &v) {
    *this = *this / v;
  }

  bool operator<(const bigint &v) const {
    if (sign != v.sign) {
      return sign < v.sign;
    }
    if (z.size() != v.z.size()) {
      return z.size() * sign < v.z.size() * v.sign;
    }
    for (int i = z.size() - 1; i >= 0; i--) {
      if (z[i] != v.z[i]) {
        return z[i] * sign < v.z[i] * sign;
      }
    }
    return false;
  }

  bool operator>(const bigint &v) const {
    return v < *this;
  }
  bool operator<=(const bigint &v) const {
    return !(v < *this);
  }
  bool operator>=(const bigint &v) const {
    return !(*this < v);
  }
  bool operator==(const bigint &v) const {
    return !(*this < v) && !(v < *this);
  }
  bool operator!=(const bigint &v) const {
    return *this < v || v < *this;
  }

  void trim() {
    while (!z.empty() && z.back() == 0) {
      z.pop_back();
    }
    if (z.empty()) {
      sign = 1;
    }
  }

  bool isZero() const {
    return z.empty() || ((int) z.size() == 1 && !z[0]);
  }

  bigint operator-() const {
    bigint res = *this;
    res.sign = -sign;
    return res;
  }

  bigint abs() const {
    bigint res = *this;
    res.sign *= res.sign;
    return res;
  }

  long long longValue() const {
    long long res = 0;
    for (int i = z.size() - 1; i >= 0; i--) {
      res = res * base + z[i];
    }
    return res * sign;
  }

  friend bigint gcd(const bigint &a, const bigint &b) {
    return b.isZero() ? a : gcd(b, a % b);
  }
  friend bigint lcm(const bigint &a, const bigint &b) {
    return a / gcd(a, b) * b;
  }

  void read(const string &s) {
    sign = 1;
    z.clear();
    int pos = 0;
    while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
      if (s[pos] == '-') {
        sign = -sign;
      }
      ++pos;
    }
    for (int i = s.size() - 1; i >= pos; i -= base_digits) {
      int x = 0;
      for (int j = max(pos, i - base_digits + 1); j <= i; j++) {
        x = x * 10 + s[j] - '0';
      }
      z.push_back(x);
    }
    trim();
  }

  friend istream &operator>>(istream &stream, bigint &v) {
    string s;
    stream >> s;
    v.read(s);
    return stream;
  }

  friend ostream &operator<<(ostream &stream, const bigint &v) {
    if (v.sign == -1) {
      stream << '-';
    }
    stream << (v.z.empty() ? 0 : v.z.back());
    for (int i = v.z.size() - 2; i >= 0; --i) {
      stream << setw(base_digits) << setfill('0') << v.z[i];
    }
    return stream;
  }

  static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
    vector<long long> p(max(old_digits, new_digits) + 1);
    p[0] = 1;
    for (int i = 1; i < (int) p.size(); i++) {
      p[i] = p[i - 1] * 10;
    }
    vector<int> res;
    long long cur = 0;
    int cur_digits = 0;
    for (int i = 0; i < (int) a.size(); i++) {
      cur += a[i] * p[cur_digits];
      cur_digits += old_digits;
      while (cur_digits >= new_digits) {
        res.push_back(cur % p[new_digits]);
        cur /= p[new_digits];
        cur_digits -= new_digits;
      }
    }
    res.push_back(cur);
    while (!res.empty() && res.back() == 0) {
      res.pop_back();
    }
    return res;
  }

  typedef vector<long long> vll;

  static vll karatsubaMultiply(const vll &a, const vll &b) {
    int n = a.size();
    vll res(n + n);
    if (n <= 32) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          res[i + j] += a[i] * b[j];
        }
      }
      return res;
    }
    int k = n >> 1;
    vll a1(a.begin(), a.begin() + k);
    vll a2(a.begin() + k, a.end());
    vll b1(b.begin(), b.begin() + k);
    vll b2(b.begin() + k, b.end());
    vll a1b1 = karatsubaMultiply(a1, b1);
    vll a2b2 = karatsubaMultiply(a2, b2);
    for (int i = 0; i < k; i++) {
      a2[i] += a1[i];
    }
    for (int i = 0; i < k; i++) {
      b2[i] += b1[i];
    }
    vll r = karatsubaMultiply(a2, b2);
    for (int i = 0; i < (int) a1b1.size(); i++) {
      r[i] -= a1b1[i];
    }
    for (int i = 0; i < (int) a2b2.size(); i++) {
      r[i] -= a2b2[i];
    }
    for (int i = 0; i < (int) r.size(); i++) {
      res[i + k] += r[i];
    }
    for (int i = 0; i < (int) a1b1.size(); i++) {
      res[i] += a1b1[i];
    }
    for (int i = 0; i < (int) a2b2.size(); i++) {
      res[i + n] += a2b2[i];
    }
    return res;
  }

  bigint operator*(const bigint &v) const {
    vector<int> a6 = convert_base(this->z, base_digits, 6);
    vector<int> b6 = convert_base(v.z, base_digits, 6);
    vll a(a6.begin(), a6.end());
    vll b(b6.begin(), b6.end());
    while (a.size() < b.size()) {
      a.push_back(0);
    }
    while (b.size() < a.size()) {
      b.push_back(0);
    }
    while (a.size() & (a.size() - 1)) {
      a.push_back(0);
      b.push_back(0);
    }
    vll c = karatsubaMultiply(a, b);
    bigint res;
    res.sign = sign * v.sign;
    for (int i = 0, carry = 0; i < (int) c.size(); i++) {
      long long cur = c[i] + carry;
      res.z.push_back(cur % 1000000);
      carry = cur / 1000000;
    }
    res.z = convert_base(res.z, 6, base_digits);
    res.trim();
    return res;
  }
};

template <typename T>
T power(T a, long long b) {
  T r = 1;
  while (b) {
    if (b & 1) {
      r *= a;
    }
    a *= a;
    b >>= 1;
  }
  return r;
}

template <typename T>
T inverse(T a, T m) {
  a = a % m;
  if (a < 0) {
    a += m;
  }
  T b = m, u = 0, v = 1;
  while (a != 0) {
    T t = b / a;
    b -= a * t;
    swap(a, b);
    u -= v * t;
    swap(u, v);
  }
  if (u < 0) {
    u += m;
  }
  return u;
}

template <int _P>
struct modnum {
  static constexpr int P = _P;

 private:
  int v;

 public:
  modnum() : v(0) {
  }

  modnum(long long _v) {
    v = _v % P;
    if (v < 0) {
      v += P;
    }
  }

  explicit operator int() const {
    return v;
  }

  bool operator==(const modnum& o) const {
    return v == o.v;
  }

  bool operator!=(const modnum& o) const {
    return v != o.v;
  }

  modnum inverse() const {
    return modnum(::inverse(v, P));
  }

  modnum operator-() const {
    return modnum(v ? P - v : 0);
  }
  
  modnum operator+() const {
    return *this;
  }

  modnum& operator++() {
    v++;
    if (v == P) {
      v = 0;
    }
    return *this;
  }
  
  modnum& operator--() {
    if (v == 0) {
      v = P;
    }
    v--;
    return *this;
  }

  modnum operator++(int) {
    modnum r = *this;
    ++*this;
    return r;
  }
  
  modnum operator--(int) {
    modnum r = *this;
    --*this;
    return r;
  }

  modnum& operator+=(const modnum& o) {
    v += o.v;
    if (v >= P) {
      v -= P;
    }
    return *this;
  }

  modnum operator+(const modnum& o) const {
    return modnum(*this) += o;
  }

  modnum& operator-=(const modnum& o) {
    v -= o.v;
    if (v < 0) {
      v += P;
    }
    return *this;
  }

  modnum operator-(const modnum& o) const {
    return modnum(*this) -= o;
  }

  modnum& operator*=(const modnum& o) {
    v = (int) ((long long) v * o.v % P);
    return *this;
  }

  modnum operator*(const modnum& o) const {
    return modnum(*this) *= o;
  }
  
  modnum& operator/=(const modnum& o) {
    return *this *= o.inverse();
  }

  modnum operator/(const modnum& o) const {
    return modnum(*this) /= o;
  }
};

template <int _P>
ostream& operator<<(ostream& out, const modnum<_P>& n) {
  return out << int(n);
}

template <int _P>
istream& operator>>(istream& in, modnum<_P>& n) {
  long long _v;
  in >> _v;
  n = modnum<_P>(_v);
  return in;
}

typedef unsigned long long ull;

template <typename T>
T power(T a, ull b) {
  T r = 1;
  while (b) {
    if (b & 1) {
      r *= a;
    }
    a *= a;
    b >>= 1;
  }
  return r;
}

namespace nimber_initializer {
const int D = 8;
const int S = 1 << D | 1;

ull table[S][S];
}

ull nimber_multiply(ull x, ull y, int d = 32) {
  using namespace nimber_initializer;
  if (x > y) {
    swap(x, y);
  }
  if (!x) {
    return 0;
  }
  if (x == 1) {
    return y;
  }
  if (y < 1 << D && table[x][y]) {
    return table[x][y];
  }
  while (y < 1ull << d) {
    d >>= 1;
  }
  ull m = (1ull << d) - 1;
  ull x0 = x & m, x1 = x >> d;
  ull y0 = y & m, y1 = y >> d;
  ull z0 = nimber_multiply(x0, y0, d >> 1);
  ull z1 = nimber_multiply(x0 ^ x1, y0 ^ y1, d >> 1);
  ull z2 = nimber_multiply(nimber_multiply(x1, y1, d >> 1), 1ull << (d - 1), d >> 1);
  ull r = (z0 ^ z1) << d | (z0 ^ z2);
  if (y < 1 << D) {
    table[x][y] = r;
  }
  return r;
}

struct nimber {
 private:
  ull v;

 public:
  nimber(ull v = 0) : v(v) {
  }

  explicit operator ull() const {
    return v;
  }

  nimber& operator+=(const nimber& o) {
    v ^= o.v;
    return *this;
  }

  nimber& operator-=(const nimber& o) {
    v ^= o.v;
    return *this;
  }

  nimber& operator*=(const nimber& o) {
    v = nimber_multiply(v, o.v);
    return *this;
  }

  nimber& operator/=(const nimber& o) {
    return *this *= o.inverse();
  }

  nimber operator+(const nimber& o) const {
    return nimber(*this) += o;
  }

  nimber operator-(const nimber& o) const {
    return nimber(*this) -= o;
  }

  nimber operator*(const nimber& o) const {
    return nimber(*this) *= o;
  }

  nimber operator/(const nimber& o) const {
    return nimber(*this) /= o;
  }

  nimber inverse() const {
    if (v <= 1) {
      return *this;
    }
    int d = 64;
    while (v < 1ull << (d >> 1)) {
      d >>= 1;
    }
    nimber r = 1;
    nimber x = *this;
    for (int i = 1; i < d; ++i) {
      x *= x;
      r *= x;
    }
    return r;
  }
};

ostream& operator<<(ostream& out, const nimber& n) {
  return out << ull(n);
}

istream& operator>>(istream& in, nimber& n) {
  ull _v;
  in >> _v;
  n = nimber(_v);
  return in;
}

const int p[7] = {3, 5, 17, 257, 641, 65537, 6700417};
const ull n = 18446744073709551615;
const nimber g = 1250686655986219608;
const int sq = 40000;

unordered_map<ull, int> mp[7];
nimber step[7];

int get(nimber h, int who) {
  nimber x = 1;
  for (int i = 0; ; ++i) {
    ull z = (ull) (h / x);
    if (mp[who].count(z)) {
      return (i * sq + mp[who][z]) % p[who];
    }
    x *= step[who];
  }
}

template <class T> pair<T, T> excrt(T m1, T a1, T m2, T a2) {
  T g = __gcd(m1, m2); m1 /= g, m2 /= g;
  if ((a2 - a1) % g != 0) return {-1, -1};
	if (m2 > m1) swap(m1, m2), swap(a1, a2);
  T m = m1 * m2 * g, a = inverse(m1, m2) * ((a2 - a1) / g % m2 + m2) % m2 * m1 * g + a1;
  return {m, a};
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 7; ++i) {
    nimber x = power(g, n / p[i]);
    nimber y = 1;
    for (int j = 0; j < sq; ++j) {
      mp[i][(ull) y] = j;
      y *= x;
    }
    step[i] = y;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    nimber a, b;
    cin >> a >> b;
    vector<int> aa(7);
    vector<int> bb(7);
    for (int i = 0; i < 7; ++i) {
      aa[i] = get(power(a, n / p[i]), i);
      bb[i] = get(power(b, n / p[i]), i);
    }
    bool valid = true;
    for (int i = 0; i < 7; ++i) {
      if (!aa[i] && bb[i]) {
        valid = false;
        break;
      }
    }
    if (valid) {
      bigint m = 1, a = 0;
      for (int i = 0; i < 7; ++i) {
        if (aa[i]) {
          bigint m0 = p[i];
          bigint a0 = (long long) bb[i] * inverse(aa[i], p[i]) % p[i];
          tie(m, a) = excrt(m, a, m0, a0);
        }
      }
      cout << a << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}