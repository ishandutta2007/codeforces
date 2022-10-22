#ifdef LOCAL
//# define _GLIBCXX_DEBUG
#endif  // LOCAL
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for(int i=(a);i<(n);++i)
#define per(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

template<typename T1, typename T2>
inline bool umin(T1& x, const T2& y) { return y < x ? x = y, true : false; }

template<typename T1, typename T2>
inline bool umax(T1& x, const T2& y) { return x < y ? x = y, true : false; }

typedef long long ll;
typedef long double ld;

const int maxn = (int) 5e5 + 5;
const int mod = (int) 1e9 + 7;
const int inf = (int) 1e9 + 17;
const ll llinf = (ll) 1e18 + 17;


int n;
vector<int> order;
vector<int> s[maxn];
vector<int> inv[maxn];
vector<int> large_s[maxn];
vector<int> large_inv[maxn];


constexpr int limit = 300;

void clear(int n, int maxa) {
  rep(i, 0, n) {
    s[i].clear();
    large_s[i].clear();
  }
  rep(i, 0, maxa) {
    inv[i].clear();
    large_inv[i].clear();
  }
  order.clear();
}

bool SolveLargeS() {
  vector<int> rows(n);
  iota(all(rows), 0);
  sort(rall(rows), [&](int x, int y) {
    return s[x].size() < s[y].size();
  });

  vector<int> inters(n, -1);
  vector<int> changes;
  for (int i : rows) {
    for (int x : s[i]) {
      for (int j : large_inv[x]) {
        if (i == j) continue;
        if (inters[j] != -1) {
          cout << i + 1 << ' ' << j + 1 << '\n';
          clear(n, order.size());
          return true;
        } else {
          inters[j] = x;
          changes.push_back(j);
        }
      }
    }
    for (int j : changes) inters[j] = -1;
    changes.clear();
  }
  return false;
}

bool SolveLargeInv() {
  vector<int> cols(order.size());
  iota(all(cols), 0);
  sort(rall(cols), [&](int x, int y) {
    return inv[x].size() < inv[y].size();
  });

  vector<int> inters(order.size(), -1);
  vector<int> changes;
  for(int x : cols) {
    for (int i : inv[x]) {
      for (int y : large_s[i]) {
        if (x == y) continue;
        if (inters[y] != -1) {
          cout << i + 1 << ' ' << inters[y] + 1 << '\n';
          clear(n, order.size());
          return true;
        } else {
          inters[y] = i;
          changes.push_back(y);
        }
      }
    }
    for (int i : changes) inters[i] = -1;
    changes.clear();
  }
  return false;
}

bool SolveEverythingSmall() {
  vector<int>* small_s = large_s;
  vector<int>* small_inv = large_inv;
  rep(i, 0, n) small_s[i].clear();
  rep(i, 0, order.size()) small_inv[i].clear();
  rep(i, 0, n) {
    for (int val : s[i]) {
      if (s[i].size() <= limit && inv[val].size() <= limit) {
        small_s[i].push_back(val);
        small_inv[val].push_back(i);
      }
    }
  }

  vector<int> inters(n, -1);
  vector<int> changes;
  rep(i, 0, n) {
    for (int x : small_s[i]) {
      for (int j : small_inv[x]) {
        if (i == j) continue;
        if (inters[j] != -1) {
          cout << i + 1 << ' ' << j + 1 << '\n';
          clear(n, order.size());
          return true;
        } else {
          inters[j] = x;
          changes.push_back(j);
        }
      }
    }
    for (int j : changes) inters[j] = -1;
    changes.clear();
  }
  return false;
}

void Solve() {
  cin >> n;
  rep(i, 0, n) {
    int m;
    cin >> m;
    s[i] = vector<int>(m);
    rep(j, 0, m) {
      cin >> s[i][j];
      order.push_back(s[i][j]);
    }
  }
  sort(all(order));
  order.erase(unique(all(order)), end(order));
  rep(i, 0, n) {
    for (int& val : s[i]) {
      val = lower_bound(all(order), val) - begin(order);
      inv[val].push_back(i);
    }
  }

  rep(i, 0, n) {
    for(int val : s[i]) {
      if (s[i].size() > limit) large_inv[val].push_back(i);
      if (inv[val].size() > limit) large_s[i].push_back(val);
    }
  }

  if (SolveLargeS()) return;
  if (SolveLargeInv()) return;
  if (SolveEverythingSmall()) return;

  clear(n, order.size());
  cout << -1 << '\n';

}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t --> 0) {
    Solve();
  }

  return 0;
}