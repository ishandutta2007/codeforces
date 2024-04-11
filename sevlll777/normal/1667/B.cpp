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
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int INF = (int) 1e18;

struct fenw {
  vector<int> tree;
  int n;

  void upd(int i, int x) {
    i += 2;
    while (i < n) {
      tree[i] = max(tree[i], x);
      i |= (i + 1);
    }
  }

  int get(int i) {
    i += 2;
    int ans = -INF;
    while (i > 0) {
      ans = max(ans, tree[i]);
      i = ((i & (i + 1)) - 1);
    }
    return ans;
  }

  fenw(int nn) {
    tree.assign(nn, -INF);
    n = nn;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> alp = {0};
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) {
    p[i] = a[i] + p[i - 1];
    alp.pb(p[i]);
  }
  sort(all(alp));
  vector<int> dp(n + 1, -INF);
  vector<int> feq(n + 1, -INF);
  fenw *boss = new fenw(n + 5);
  dp[0] = 0;
  int lb = lower_bound(all(alp), 0) - alp.begin();
  boss->upd(lb, 0);
  feq[lb] = max(feq[lb], dp[0]);
  for (int i = 1; i <= n; i++) {
    lb = lower_bound(all(alp), p[i]) - alp.begin();
    int kek = boss->get(lb - 1);
    dp[i] = kek + i;
    if (dp[i] < feq[lb]) {
      dp[i] = feq[lb];
    }
    if (a[i] > 0) {
      dp[i] = max(dp[i], dp[i - 1] + 1);
    } else if (a[i] == 0) {
      dp[i] = max(dp[i], dp[i - 1]);
    } else {
      dp[i] = max(dp[i], dp[i - 1] - 1);
    }
    feq[lb] = max(feq[lb], dp[i]);
    boss->upd(lb, dp[i] - i);
  }
  cout << dp[n] << '\n';
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