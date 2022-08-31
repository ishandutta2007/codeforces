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

const int LOG = 60;

using num = modnum<998244353>;
using num2 = modnum<1004535809>;
using ll = long long;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<num2> bin(LOG + 1);
  bin[0] = 1;
  for (int i = 0; i < LOG; ++i) {
    bin[i + 1] = bin[i] * 2;
  }
  int na;
  cin >> na;
  vector<pair<ll, num2>> a(na * 2);
  for (int i = 0; i < na; ++i) {
    cin >> a[i * 2].first;
    a[i * 2].second = -1;
    cin >> a[i * 2 + 1].first;
    a[i * 2 + 1].first++;
    a[i * 2 + 1].second = 1;
  }
  na *= 2;
  int nb;
  cin >> nb;
  vector<pair<ll, num2>> b(nb * 2);
  for (int i = 0; i < nb; ++i) {
    cin >> b[i * 2].first;
    b[i * 2].second = -1;
    cin >> b[i * 2 + 1].first;
    b[i * 2 + 1].first++;
    b[i * 2 + 1].second = 1;
  }
  map<ll, num2> sum;
  auto solve = [&](ll x, ll y, num2 z) {
    for (int rot = 0; rot < 2; ++rot) {
      for (int i = LOG - 1; ~i; --i) {
        if (x >> i & 1) {
          ll fix = (((x >> i) ^ 1) << i) ^ (y >> i << i);
          num2 add = 0;
          for (int j = i - 1; ~j; --j) {
            if (y >> j & 1) {
              add += bin[j];
            }
          }
          sum[fix] += z * add;
          sum[fix + (1ll << i)] -= z * add;
        }
      }
      swap(x, y);
    }
    for (int i = LOG - 1; ~i; --i) {
      if ((x >> i & 1) && (y >> i & 1)) {
        ll fix = (((x >> i) ^ 1) << i) ^ (((y >> i) ^ 1) << i);
        sum[fix] += z * bin[i];
        sum[fix + (1ll << i)] -= z * bin[i];
      }
    }
  };
  for (auto aa : a) {
    for (auto bb : b) {
      solve(aa.first, bb.first, aa.second * bb.second);
    }
  }
  num ans = 0;
  num2 cur = 0;
  auto get = [&](ll l, ll r) {
    return (num) (l + r - 1) * (r - l) / 2;
  };
  for (auto it = sum.begin(); it != --sum.end(); ++it) {
    cur += it->second;
    if (cur != 0) {
      ans += get(it->first, next(it)->first);
    }
  }
  cout << ans << "\n";
  return 0;
}