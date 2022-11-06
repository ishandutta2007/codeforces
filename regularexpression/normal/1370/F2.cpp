#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()

int cnt = 0;

pair<int, int> ask(vector<int> v) {
  assert(!v.empty());
  cnt++;
  if (cnt > 11) assert(0);
  cout << "? " << SZ(v);
  for (auto it : v) cout << " " << it + 1;
  cout << endl;
  pair<int, int> p;
  cin >> p.F >> p.S;
  if (p == mp(-1LL, -1LL)) exit(0);
  p.F--;
  return p;
}

const int N = 1005;

int n;
vector<int> g[N];
int h[N];

void dfs(int v, int pr = -1) {
  for (auto to : g[v]) {
    if (to != pr) {
      h[to] = h[v] + 1;
      dfs(to, v);
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) g[i].clear();
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  cnt = 0;
  vector<int> kek;
  for (int i = 0; i < n; i++) kek.pb(i);
  auto flex = ask(kek);
  int st = flex.F, dst = flex.S;
  h[st] = 0;
  dfs(st);
  int mx = 0;
  for (int i = 0; i < n; i++) mx = max(mx, h[i]);
  int l = (dst + 1) / 2, r = min(mx + 1, dst + 1);
  int lst = -1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    kek.clear();
    for (int i = 0; i < n; i++) {
      if (h[i] >= mid) kek.pb(i);
    }
    flex = ask(kek);
    if (flex.S == dst) {
        lst = flex.F;
        l = mid;
    } else r = mid;
  }
  int s;
  if (lst == -1) {
    vector<int> kek;
    for (int i = 0; i < n; i++) {
      if (h[i] >= l) kek.pb(i);
    }
    s = ask(kek).F;
  } else s = lst;
  h[s] = 0;
  dfs(s);
  kek.clear();
  for (int i = 0; i < n; i++) {
    if (h[i] == dst) kek.pb(i);
  }
  int f = ask(kek).F;
  cout << "! " << s + 1 << " " << f + 1 << endl;
  string orz;
  cin >> orz;
  if (orz == "Incorrect") exit(0);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}