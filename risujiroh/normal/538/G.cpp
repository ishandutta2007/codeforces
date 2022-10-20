#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

mt19937 mt_engine(chrono::steady_clock::now().time_since_epoch().count());
template <class T> enable_if_t<is_integral_v<T>, T> rng(T l, T r) {
  return uniform_int_distribution<T>(l, r - 1)(mt_engine);
}
template <class T> enable_if_t<is_floating_point_v<T>, T> rng(T l, T r) {
  return uniform_real_distribution<T>(l, r)(mt_engine);
}

struct stopwatch {
  clock_t t = clock();
  void restart() { t = clock(); }
  int elapsed() const { return (clock() - t) * 1000 / CLOCKS_PER_SEC; }
  void operator()(string s = "Time") const {
    cerr << s + ": " << elapsed() << " ms\n";
  }
};

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };
auto chmax = [](auto&& a, auto b) { return a < b ? a = b, 1 : 0; };

using ll = long long;

ll fdiv(ll a, ll b) {
  return a / b - ((a ^ b) < 0 and a % b);
}
ll cdiv(ll a, ll b) {
  return a / b + ((a ^ b) >= 0 and a % b);
}

ll n, m;

vector<ll> f(const vector<ll>& t, const vector<ll>& x) {
  vector<ll> q(n), r(n);
  ll lb = -m, ub = m;
  for (int i = 0; i < n; ++i) {
    q[i] = t[i] / m, r[i] = t[i] - q[i] * m;
    if (q[i]) {
      chmax(lb, cdiv(x[i] - r[i], q[i]));
      chmin(ub, fdiv(x[i] + r[i], q[i]));
    }
    chmax(lb, cdiv(x[i] - (m - r[i]), q[i] + 1));
    chmin(ub, fdiv(x[i] + (m - r[i]), q[i] + 1));
  }
  lb += (m + lb) & 1;
  ub -= (m + ub) & 1;
  if (lb > ub) {
    return {};
  }
  vector<ll> v;
  auto chk = [&](ll a) {
    v = vector(m + 1, inf<ll>);
    v[0] = 0, v[m] = a;
    for (int i = 0; i < n; ++i) {
      ll nx = x[i] - q[i] * a;
      if (v[r[i]] != inf<ll> and v[r[i]] != nx) {
        return false;
      }
      v[r[i]] = nx;
    }
    for (int i = 0; i < m; ++i) {
      chmin(v[i + 1], v[i] + 1);
    }
    for (int i = m; i--; ) {
      chmin(v[i], v[i + 1] + 1);
    }
    if (v[0] != 0 or v[m] != a) {
      return false;
    }
    for (int i = 0; i < n; ++i) {
      ll nx = x[i] - q[i] * a;
      if (v[r[i]] != nx) {
        return false;
      }
    }
    return true;
  };
  for (stopwatch sw; sw.elapsed() < 500; ) {
    ll a = lb + 2 * rng<ll>(0, (ub - lb) / 2 + 1);
    if (chk(a)) {
      for (int i = 0; i < m; ++i) {
        v[i] = v[i + 1] - v[i];
      }
      v.pop_back();
      return v;
    }
  }
  return {};
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  vector<ll> t(n), x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> x[i] >> y[i];
  }
  vector<ll> z(n);
  for (int i = 0; i < n; ++i) {
    if ((t[i] + x[i] + y[i]) & 1) {
      cout << "NO\n";
      exit(0);
    }
    z[i] = x[i] + y[i];
  }
  auto a = f(t, z);
  for (int i = 0; i < n; ++i) {
    z[i] = y[i] - x[i];
  }
  auto b = f(t, z);
  if (empty(a) or empty(b)) {
    cout << "NO\n";
    exit(0);
  }
  for (int i = 0; i < m; ++i) {
    if (a[i] == 1 and b[i] == 1) {
      cout << 'U';
    } else if (a[i] == 1) {
      cout << 'R';
    } else if (b[i] == 1) {
      cout << 'L';
    } else {
      cout << 'D';
    }
  }
  cout << '\n';
}