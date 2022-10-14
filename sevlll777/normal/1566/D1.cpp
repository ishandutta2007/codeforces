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
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

void solve() {
  int n, m;
  cin >> m >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  map<int, vector<int>> B;
  for (int i = 0; i < n; i++) {
    B[A[i]].pb(i);
  }
  vector<vector<int>> BB;
  for (auto p : B) {
    reverse(all(p.second));
    BB.pb(p.second);
  }
  int now = 0;
  vector<int> kek(n);
  for (auto p : BB) {
    for (int i = now; i < now + p.size(); i++) {
      kek[i] = p[i - now];
    }
    now += p.size();
  }
  ordered_set aboba;
  int ans = 0;
  for (auto num : kek) {
    ans += (aboba.size() - aboba.order_of_key(num));
    aboba.insert(num);
  }
  cout << n * (n - 1) / 2 - ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}