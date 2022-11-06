#include<bits/stdc++.h>
using namespace std;

typedef __int128 ll;
typedef long double ld;

void solve() {
  int n, k;
  cin >> n >> k;
  auto f = [&] (ll x) {
    int sum = 0;
    while (x > 0) {
      sum += x % 10;
      x /= 10;
    }
    return sum;
  };
  const ll inf = 9e18 + 7;
  ll ans = inf;
  for (int lst = 0; lst < 10; lst++) {
    for (int cnt = 0; cnt <= 18; cnt++) {
      for (int fst = 0; fst < 9; fst++) {
        ll num = fst;
        for (int i = 0; i < cnt; i++)
          num = num * 10 + 9;
        num = num * 10 + lst;
        int sum = 0;
        for (ll i = num; i <= num + k; i++)
          sum += f(i);
        if (sum <= n) {
          int ost = n - sum;
          if (ost % (k + 1) != 0)
            continue;
          int need = (ost + k) / (k + 1);
          vector<ll> v;
          if (need % 9 != 0)
            v.push_back(need % 9);
          for (int i = 0; i < need / 9; i++)
            v.push_back(9);
          ll go = 0;
          for (ll x : v)
            go = go * 10 + x;
          go = go * 10 + fst;
          for (int i = 0; i < cnt; i++)
            go = go * 10 + 9;
          go = go * 10 + lst;
          ans = min(ans, go);
        }
      }
    }
  }
  if (ans == inf)
    cout << "-1\n";
  else
    cout << (long long) ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}