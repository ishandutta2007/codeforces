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

int inverse(int a, int m) {
  a %= m;
  if (a < 0) {
    a += m;
  }
  int b = m, u = 0, v = 1;
  while (a) {
    int t = b / a;
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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int m = 0;
  for (int i = 0; i < n; ++i) {
    m += a[i];
  }
  vector<num> fact(m + n);
  fact[0] = 1;
  for (int i = 1; i < m + n; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  vector<num> inv_fact(m + n);
  for (int i = 0; i < m + n; ++i) {
    inv_fact[i] = num(1) / fact[i];
  }
  int p = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] < i) {
      p = i;
      break;
    }
  }
  num ans = 0;
  if (p == -1) {
    vector<int> b(n);
    int free = m;
    for (int i = 0; i < n; ++i) {
      ++b[a[i] % n];
      free -= a[i] % n;
    }
    free /= n;
    for (int d = 0; d < n; ++d) {
      ans += fact[free + n - 1] * inv_fact[n - 1] * inv_fact[free];
      free += 1 - b[d];
    }
  } else {
    ++ans;
    for (int i = 1, j = 0; i < p; ++i) {
      while (j < n && a[j] < i) {
        ++j;
      }
      ans += fact[i - j + n - 1] * inv_fact[n - 1] * inv_fact[i - j];
    }
  }
  cout << ans << "\n";
  return 0;
}