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

struct DSU {
  vector <int> r, p;
  int n;

  DSU(int n) : n(n), r(n, 0), p(n, 0) {
    iota(all(p), 0);
  }

  int get(int v) {
    if (p[v] == v) {
      return v;
    }
    return p[v] = get(p[v]);
  }

  bool uni(int v, int u) {
    v = get(v);
    u = get(u);
    if (v == u) {
      return false;
    }

    if (r[v] == r[u]) ++r[u];
    if (r[v] > r[u]) swap(v, u);
    p[v] = u;
    return true;
  }
};

vector <vector<int>> gr;
vector <int> h;
vector <int> pr;
vector <bool> on_cycle;
vector <ll> a, b;

void dfs(int v, int p, int he) {
  h[v] = he;
  pr[v] = p;
  for (int u : gr[v]) {
    if (u == p) continue;
    dfs(u, v, he + 1);
  }
}

void add_dfs(int v, int p) {
  for (int u : gr[v]) {
    if (u == p || on_cycle[u]) continue;
    add_dfs(u, v);
  }
  ll d = b[v] - a[v];
  if (p != -1) {
    a[v] += d;
    a[p] += d;
  }
}

void solve() {
  int n, m;
  cin >> n >> m;


  a.assign(n, 0);
  b.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    sum += (b[i] - a[i]);
  }

  vector <pair <int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].x >> edges[i].y;
    edges[i].x--, edges[i].y--;
  }

  DSU dsu(n);
  gr.assign(n, {});
  h.assign(n, 0);
  pr.assign(n, -1);

  vector <bool> used(m, false);
  for (int i = 0; i < m; ++i) {
    int v = edges[i].x, u = edges[i].y;
    if (dsu.uni(v, u)) {
      used[i] = true;
      gr[v].pb(u);
      gr[u].pb(v);
    }
  }

  dfs(0, -1, 0);

  on_cycle.assign(n, false);

  int cycle_edge = -1;

  for (int i = 0; i < m; ++i) {
    if (used[i]) continue;
    int v = edges[i].x, u = edges[i].y;
    if ((h[v] + h[u]) % 2 == 0) {
      gr[v].pb(u);
      gr[u].pb(v);

      used[i] = true;
      if (h[v] > h[u]) {
        swap(v, u);
      }
      cycle_edge = i;

      while (h[u] > h[v]) {
        on_cycle[u] = true;
        u = pr[u];
      }
      while (u != v) {
        on_cycle[u] = true;
        on_cycle[v] = true;
        u = pr[u], v = pr[v];
      }
      on_cycle[v] = true;
      break;
    }
  } 

  for (int v = 0; v < n; ++v) {
    if (!on_cycle[v] && cycle_edge != -1) continue;
    add_dfs(v, -1);
    if (cycle_edge == -1) {
      break;
    }
  }

  if (cycle_edge == -1) {
    cout << (a[0] == b[0] ? "YES\n" : "NO\n");
  } else {
    cout << (sum % 2 ? "NO\n" : "YES\n");
  }
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}