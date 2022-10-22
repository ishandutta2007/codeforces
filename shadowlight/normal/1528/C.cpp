#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

struct Rollback {
  bool add;
  int l, r;
};

vector <vector<Rollback>> hist;

vector <pair <int, int>> segs;
vector <vector<int>> tree1, tree2;

int timer = 0;
void dfs2(int v) {
  segs[v].x = timer;
  segs[v].y = timer++;
  for (int u : tree2[v]) {
    dfs2(u);
    segs[v].y = max(segs[v].y, segs[u].y);
  }
}

int res = 0, now = 0;
set <pair <int, int>> q;

void dfs1(int v) {
  int a = segs[v].x, b = segs[v].y;
  auto it = q.lower_bound({a, -1});
  hist[v].clear();

  if (it != q.begin()) {
    --it;
    if (it->y >= b) {
      hist[v].pb({false, it->x, it->y});
      q.erase(it);
    }
  }
  q.insert({a, b});
  res = max(res, (int)q.size());

  for (int u : tree1[v]) {
    dfs1(u);
  }

  q.erase({a, b});
  for (auto t : hist[v]) {
    q.insert({t.l, t.r});
  }
}

void solve() {
  int n;
  cin >> n;
  hist.assign(n, {});
  segs.assign(n, {-1, -1});
  tree1.assign(n, {});
  tree2.assign(n, {});

  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    tree1[p].pb(i);
  }

  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    tree2[p].pb(i);
  }

  timer = 0;
  dfs2(0);

  q.clear();
  res = 0, now = 0;
  dfs1(0);
  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}