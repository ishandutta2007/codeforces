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
  int n;
  cin >> n;
  vector<int> x(n + 1), y(n + 1), t(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i] >> t[i];
  }
  vector<int> z(n + 1);
  for (int i = 1; i <= n; ++i) {
    z[i] = lower_bound(x.begin(), x.end(), y[i]) - x.begin();
  }
  vector<num> f(n + 1);
  vector<num> s(n + 1);
  for (int i = 1; i <= n; ++i) {
    f[i] += x[i] - x[i - 1];
    f[i] += s[i - 1] - s[z[i] - 1];
    f[i] += x[i] - x[i - 1];
    f[i] -= y[i] - x[z[i] - 1];
    s[i] = s[i - 1] + f[i];
  }
  num ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (t[i]) {
      ans += f[i];
    } else {
      ans += x[i] - x[i - 1];
    }
  }
  cout << ans + 1 << "\n";
  return 0;
}