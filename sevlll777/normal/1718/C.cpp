#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
// #define int long long
typedef long long ll;
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int N = 200500;
bool sve[N];

void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> d;
  vector<vector<ll>> fr(n + 1);
  vector<multiset<ll>> fr2(n + 1);
  for (int x = 1; x < n; x++) {
    if (n % x == 0 && !sve[n / x]) {
      d.pb(x);
      vector<ll> b = a;
      for (int i = x; i < n; i++) {
        b[i] += b[i - x];
      }
      for (int i = n - x; i < n; i++) {
        fr[x].pb(b[i]);
        fr2[x].insert(b[i]);
      }
    }
  }
  ll ans = 0;
  for (auto x : d) {
    ans = max(ans, x * (*fr2[x].rbegin()));
  }
  cout << ans << '\n';
  while (q--) {
    int p;
    ll v;
    cin >> p >> v;
    p--;
    ll dif = v - a[p];
    ans = 0;
    for (auto x : d) {
      int r = p % x;
      fr2[x].erase(fr2[x].find(fr[x][r]));
      fr[x][r] += dif;
      fr2[x].insert(fr[x][r]);
      ans = max(ans, x * (*fr2[x].rbegin()));
    }
    a[p] = v;
    cout << ans << '\n';
  }

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  sve[1] = true;
  for (int x = 2; x < N; x++) {
    if (!sve[x]) {
      for (int y = x + x; y < N; y += x) {
        sve[y] = true;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}