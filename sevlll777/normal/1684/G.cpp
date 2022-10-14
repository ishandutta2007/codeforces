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
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int N = 2022;
vector<int> g[N];
int match[N];
bitset<N> used;

bool dfs(int v) {
  if (used[v]) {
    return false;
  }
  used[v] = true;
  for (auto u : g[v]) {
    if (match[u] == -1 || dfs(match[u])) {
      match[u] = v;
      return true;
    }
  }
  return false;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  if (a[n - 1] > (m - 1) / 2) {
    cout << "-1\n";
    return 0;
  }
  vector<int> big, small;
  for (auto x : a) {
    if (x > m / 3) {
      big.pb(x);
    } else {
      small.pb(x);
    }
  }
  int s1 = (int) big.size();
  int s2 = (int) small.size();
  for (int i = 0; i < s1; i++) {
    for (int j = 0; j < s2; j++) {
      if (big[i] % small[j] == 0 && 2 * big[i] + small[j] <= m) {
        g[i].pb(s1 + j);
        g[s1 + j].pb(i);
      }
    }
  }

  vector<pair<int, int>> kek;
  memset(match, -1, sizeof(int) * N);
  for (int v = 0; v < s1; v++) {
    used.reset();
    dfs(v);
  }
  vector<bool> us(n, false);
  vector<pair<int, int>> ps;
  int ans = 0;
  for (int v = 0; v < s1 + s2; v++) {
    if (match[v] != -1) {
      us[v] = true;
      us[match[v]] = true;
      ps.pb({v, match[v]});
      ans++;
    }
  }

  assert(ans <= big.size());
  if (ans < big.size()) {
    cout << "-1\n";
    return 0;
  }
  vector<pair<int, int>> answ;
  for (int i = 0; i < ps.size(); i++) {
    int x1 = ps[i].first, x2 = ps[i].second;
    if (x1 > x2) {
      swap(x1, x2);
    }
    x2 -= s1;
    answ.pb({big[x1] + small[x2], 2 * big[x1] + small[x2]});
  }

  for (int i = 0; i < n; i++) {
    if (!us[i]) {
      assert(i >= s1);
      int num = small[i - s1];
      answ.pb({2 * num, 3 * num});
    }
  }

  cout << answ.size() << '\n';
  for (auto p : answ) {
    cout << p.first << ' ' << p.second << '\n';
  }


}