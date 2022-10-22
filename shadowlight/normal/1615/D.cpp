#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
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

int n, m;
vector<vector<int>> gr;

struct DSU {
  int n;
  vector<int> p, r;

  DSU(int n) : n(n), p(n), r(n) {
    iota(all(p), 0);
  }

  int get(int v) {
    return (p[v] == v ? v : p[v] = get(p[v]));
  }

  bool uni(int v, int u) {
    v = get(v);
    u = get(u);
    if (v == u) return false;
    if (r[v] == r[u]) ++r[u];
    if (r[v] > r[u]) swap(v, u);
    p[v] = u;

    return true;
  }
};

vector<int> col;
bool recolor(int v, int colour) {
  if (col[v] != -1) {
    return col[v] == colour;
  }
  col[v] = colour;
  for (int u : gr[v]) {
    if (!recolor(u, colour ^ 1)) {
      return false;
    }
  }
  return true;
}

struct Edge {
  int v, u, w;
};

void solve() {
  cin >> n >> m;
  gr.assign(n, {});

  DSU dsu(n);

  vector<pair<int, int>> edges;
  vector<Edge> in_edges;

  for (int i = 1; i < n; ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    --v, --u;
    in_edges.pb({v, u, w});
    
    if (w == -1) continue;

    int cnt = 0;
    for (int i = 0; i < 30; ++i) {
      if ((1 << i) & w) {
        cnt ^= 1;
      }
    }
    if (cnt) {
      edges.pb({v, u});
    } else {
      dsu.uni(v, u);
    }
  }

  for (int i = 0; i < m; ++i) {
    int v, u, p;
    cin >> v >> u >> p;
    --v, --u;
    if (!p) {
      dsu.uni(v, u);
    } else {
      edges.pb({v, u});
    }
  }

  for (auto [v, u] : edges) {
    v = dsu.get(v);
    u = dsu.get(u);
    if (v == u) {
      cout << "NO\n";
      return;
    }
    gr[v].pb(u);
    gr[u].pb(v);
  }

  col.assign(n, -1);
  for (int i = 0; i < n; ++i) {
    if (col[i] != -1) continue;
    if (!recolor(i, 0)) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
  for (auto t : in_edges) {
    cout << t.v + 1 << " " << t.u + 1 << " ";
    if (t.w != -1) {
      cout << t.w << "\n";
      continue;
    }

    int v = dsu.get(t.v), u = dsu.get(t.u);
    cout << (col[v] != col[u]) << "\n";
  }
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}