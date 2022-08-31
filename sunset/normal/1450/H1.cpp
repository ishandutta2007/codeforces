#include <bits/stdc++.h>

using namespace std;

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
  a %= m;
  if (a < 0) {
    a += m;
  }
  T b = m, u = 0, v = 1;
  while (a) {
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

using num = modnum<998244353>;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<num> fact(n + 1), inv_fact(n + 1);
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i;
    inv_fact[i] = inv_fact[i - 1] / i;
  }
  auto binom = [&](int x, int y) {
    if (x < y || y < 0) {
      return num(0);
    } else {
      return fact[x] * inv_fact[y] * inv_fact[x - y];
    }
  };
  int w = 0, b = 0, e = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'w') {
      w += i & 1;
      b += !(i & 1);
    } else if (s[i] == 'b') {
      w += !(i & 1);
      b += i & 1;
    } else {
      e++;
    }
  }
  int d = abs(w - b);
  num ans = 0;
  for (int i = 0; i <= e; ++i) {
    if ((d + i * 2 - e) % 4 == 0) {
      ans += binom(e, i) * abs(d + i * 2 - e);
    }
  }
  ans /= power(num(2), e + 1);
  cout << ans << "\n";
  return 0;
}