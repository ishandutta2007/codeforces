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

struct Edge {
  int v, u, w;
};

bool operator<(Edge a, Edge b) {
  return a.w < b.w;
}

vector <Edge> edges;
vector <Edge> edgesn;

struct DSU {
  int n;
  int cnt;
  vector <int> p, r;
  DSU(int n) : n(n), p(n), r(n, 0) {
    iota(all(p), 0);
    cnt = n;
  }

  int get(int v) {
    return (p[v] == v ? v : p[v] = get(p[v]));
  }

  bool united(int v, int u) {
    return get(v) == get(u);
  }

  void uni(int v, int u) {
    v = get(v);
    u = get(u);    
    if (v == u) {
      return;
    }
    if (r[v] == r[u]) ++r[u];
    if (r[v] > r[u]) swap(v, u);
    p[v] = u;
    --cnt;
  }
};
const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m;
  cin >> n >> m;

  int x = 0;
  for (int i = 0; i < m; ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    --v, --u;
    edges.pb({v, u, w});
    x ^= w;
  }


  sort(all(edges));

  DSU dsu_start(n);
  for (auto e : edges) {
    if (dsu_start.united(e.v, e.u)) continue;
    dsu_start.uni(e.v, e.u);
    edgesn.pb(e); 
  }


  ll rem = n * (ll) (n - 1) / 2 - m;
  bool has_cycle = false;

  if (rem >= m) {
    has_cycle = true;
  } else {
    vector <vector<bool>> has(n, vector<bool>(n, false));
    for (auto e : edges) {
      has[e.v][e.u] = true;
      has[e.u][e.v] = true;
    }
    DSU dsu_pr(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if(!has[i][j]) {
          if (dsu_pr.united(i, j)) {
            has_cycle = true;
          } else {
            dsu_pr.uni(i, j);
          }
        }
      }
    }
  }

  //cout << x << " " << has_cycle << endl;

  vector <vector<int>> gr(n);
  for (auto e : edges) {
    gr[e.v].pb(e.u);
    gr[e.u].pb(e.v);
  }
  for (int i = 0; i < n; ++i) {
    sort(all(gr[i]));
  }

  set <pair <int, int>> groups;

  DSU dsu(n);
  for (int i = 0; i < n; ++i) {
    groups.insert({i, i});
  }

  for (int v = 0; v < n; ++v) {
    int pr = -1;
    for (int u : gr[v]) {
      int l = pr + 1, r = u - 1;
      pr = u;
      if (l > r) continue;
      auto it = groups.lower_bound({l, INF});
      assert(it != groups.begin());
      --it;
      int lefter = it->x;
      int righter = it->y;

      while (it != groups.end() && it->x <= r) {
        righter = it->y;
        dsu.uni(v, righter);
        //cout << "UNI: " << v << " " << righter << endl;
        groups.erase(it++);
      }
      groups.insert({lefter, righter});
    }
    int l = pr + 1, r = n - 1;
    if (l > r) continue;
    auto it = groups.lower_bound({l, INF});
    assert(it != groups.begin());
    --it;
    int lefter = it->x;
    int righter = it->y;

    while (it != groups.end() && it->x <= r) {
      righter = it->y;
      dsu.uni(v, righter);
      //cout << "UNI: " << v << " " << righter << endl;
      groups.erase(it++);
    }
    groups.insert({lefter, righter});
  }
  ll res = 0;
  bool withx = false;
  if (!has_cycle) {
    withx = true;
    res += x;
  }

  for (auto e : edgesn) {
    if (dsu.united(e.v, e.u)) {
      if (withx && e.w < x) {
        res -= x;
        withx = false;
        res += e.w;
      }
      continue;
    }
    res += e.w;
    dsu.uni(e.v, e.u); 
  }
  cout << res << "\n";
}