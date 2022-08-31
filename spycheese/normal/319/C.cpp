#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;

template<typename F>
ll dp1D1D(int n, F const& w) {
  if (n == 0) return 0;
  vector<ll> d(n + 1, 0);
  struct Elem {
    int i, k;
    ll d;
  };
  vector<Elem> q = {{1, 0, w(0, 1)}};
  int qi = 0;
  for (int i = 1; i < n; ++i) {
    d[i] = q[qi].d;
    if (qi != sz(q) - 1 && q[qi + 1].i == i + 1)
      ++qi;
    else {
      ++q[qi].i;
      int k = q[qi].k;
      q[qi].d = d[k] + w(k, i + 1);
    }

    int cr = n + 1;
    ll nd = -1;
    while (sz(q) > qi) {
      auto const& e = q.back();
      ll cd = d[i] + w(i, e.i);
      if (e.d > cd) {
        nd = cd;
        cr = e.i;
        q.pop_back();
      } else
        break;
    }
    if (sz(q) == qi) {
      q.push_back({i + 1, i, d[i] + w(i, i + 1)});
    } else {
      auto const& e = q.back();
      int cl = e.i;
      while (cr - cl > 1) {
        int mid = (cl + cr) / 2;
        ll cd = d[i] + w(i, mid);
        if (cd < d[e.k] + w(e.k, mid)) {
          nd = cd;
          cr = mid;
        } else {
          cl = mid;
        }
      }
      if (cr != n + 1)
        q.push_back({cr, i, nd});
    }
  }
  return q[qi].d;
}

template<typename F>
ll dp1D1D_slow(int n, F const& w) {
  vector<ll> d(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    d[i] = w(0, i);
    for (int j = 1; j < i; ++j)
      d[i] = min(d[i], d[j] + w(j, i));
  }
  return d[n];
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (ll &x : a) cin >> x;
  for (ll &x : b) cin >> x;
  cout << dp1D1D(n - 1, [&](int l, int r) {
    return b[l] * a[r];
  });
}