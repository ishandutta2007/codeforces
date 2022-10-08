#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}
const int maxn = 1010;
int wase[maxn * maxn];
int wasv[maxn];
int pr[maxn];
vector<pair<int, int>> g[2][maxn];
vector<int> ls[2];
void euler_cycle(int v, int d) {
  while (sz(g[d][v]) > 0) {
    pair<int, int> p = g[d][v].back();
    g[d][v].pop_back();
    if (wase[p.y] == 0) {
      wase[p.y] = 1;
      euler_cycle(p.x, d ^ 1);
      ls[d].pb(p.y);
    }
  }
}
vector<pair<int, int>> sub(vector<pair<int, int>>& e, vector<int>& id) {
  vector<pair<int, int>> ans(sz(id));
  for (int i = 0; i < sz(id); i++) {
    ans[i] = e[id[i]];
  }
  return ans;
}
vector<pair<int, int>>* cur_edges;
int CNT = 0;
bool find_chain(int v) {
  wasv[v] = CNT;
  for (const auto& p : g[0][v]) {
    if (pr[p.x] == -1) {
      pr[p.x] = p.y;
      return true;
    }
  }
  for (const auto& p : g[0][v]) {
    assert(pr[p.x] != -1);
    int v2 = (*cur_edges)[pr[p.x]].x;
    if (wasv[v2] != CNT && find_chain(v2)) {
      pr[p.x] = p.y;
      return true;
    }
  }
  return false;
}
vector<int> solve(int n, int mx, vector<pair<int, int>> edges) {
  // T(V, E) = 2 T(V, E / 2) + VE
  // T(V, E) = V E log E
  // but initially we need E = V^2, so we get O(V^3 log V)
  assert(sz(edges) == n * mx);
  if (mx == 0) {
    return vector<int>(0);
  }
  if (mx == 1) {
    return vector<int>(sz(edges), 1);
  }
  if (mx % 2 == 0) {
    for (int i = 0; i < n; i++) {
      g[0][i].clear();
      g[1][i].clear();
    }
    for (int i = 0; i < sz(edges); i++) {
      wase[i] = 0;
    }
    ls[0].clear();
    ls[1].clear();
    for (int i = 0; i < sz(edges); i++) {
      g[0][edges[i].x].pb(mp(edges[i].y, i));
      g[1][edges[i].y].pb(mp(edges[i].x, i));
    }
    for (int i = 0; i < n; i++) {
      euler_cycle(i, 0);
    }
    vector<int> e1 = ls[0];
    vector<int> e2 = ls[1];
    assert(sz(e1) == n * mx / 2);
    assert(sz(e2) == n * mx / 2);
    vector<int> ans(sz(edges), 0);
    vector<int> ans1 = solve(n, mx / 2, sub(edges, e1));
    vector<int> ans2 = solve(n, mx / 2, sub(edges, e2));
    for (int i = 0; i < sz(e1); i++) {
      ans[e1[i]] = ans1[i];
    }
    for (int i = 0; i < sz(e2); i++) {
      ans[e2[i]] = ans2[i] + mx / 2;
    }
    return ans;
  } else {
    for (int i = 0; i < n; i++) {
      g[0][i].clear();
      pr[i] = -1;
      wasv[i] = 0;
    }
    for (int i = 0; i < sz(edges); i++) {
      g[0][edges[i].x].pb(mp(edges[i].y, i));
    }
    cur_edges = &edges;
    for (int i = 0; i < n; i++) {
      CNT++;
      assert(find_chain(i));
    }    
    vector<int> ans(sz(edges), 0);
    for (int i = 0; i < n; i++) {
      assert(pr[i] != -1);
      ans[pr[i]] = 1;
    }
    vector<int> e1;
    for (int i = 0; i < sz(edges); i++) if (ans[i] == 0) {
      e1.pb(i);
    }
    vector<int> ans1 = solve(n, mx - 1, sub(edges, e1));
    for (int i = 0; i < sz(e1); i++) {
      ans[e1[i]] = ans1[i] + 1;
    }
    return ans;
  }
}
int main(){
  #ifdef home
  assert(freopen("output.txt","wt",stdout));
  assert(freopen("input.txt","rt",stdin));
  #endif
  int n1, n2, m;
  scanf("%d %d %d", &n1, &n2, &m);
  int n = max(n1, n2);
  vector<pair<int, int>> edges;
  vector<int> deg1(n, 0);
  vector<int> deg2(n, 0);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    deg1[x]++;
    deg2[y]++;
    edges.pb(mp(x,y));
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, deg1[i]);
    mx = max(mx, deg2[i]);
  }
  int cur = 0;
  for (int i = 0; i < n; i++) {
    while (deg1[i] < mx) {
      while (deg2[cur] == mx) {
        cur++;
      }
      edges.pb(mp(i, cur));
      deg1[i]++;
      deg2[cur]++;
    }
  }
  for (int i = 0; i < n; i++) {
    assert(deg1[i] == mx && deg2[i] == mx);
  }
  vector<int> ans = solve(n, mx, edges);
  printf("%d\n", mx);
  for (int i = 0; i < m; i++) {
    printf("%d%c", ans[i], " \n"[i + 1 == m]);
  }
  return 0;
}