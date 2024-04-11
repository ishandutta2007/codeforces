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

const int N = 2e5 + 7;
vector <pair <int, int>> gr[N];
vector <pair <int, int>> rgr[N];
int col[N];
bool used[N];

vector <int> order;
void dfs(int v) {
  if (used[v]) return;
  used[v] = true;
  for (auto [u, l] : gr[v]) {
    dfs(u);
  }
  order.pb(v);
}

void rdfs(int v, int color) {
  if (col[v]) return;
  col[v] = color;
  for (auto [u, l] : rgr[v]) {
    rdfs(u, color);
  }
}

ll len[N];

ll G = 0;
void sdfs(int v, ll L = 0) {
  used[v] = true;
  len[v] = L;
  order.pb(v);
  for (auto [u, l] : gr[v]) {
    if (col[u] != col[v]) continue;
    if (used[u]) {
      G = __gcd(G, l + L - len[u]);
    } else {
      sdfs(u, L + l);
    }
  }
}

ll g[N];

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m, q;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int v, u, l;
    cin >> v >> u >> l;
    --v, --u;
    gr[v].pb({u, l});
    rgr[u].pb({v, l});
  }

  for (int v = 0; v < n; ++v) {
    if (used[v]) continue;
    dfs(v);
  }
  int now = 0;
  reverse(all(order));
  for (int u : order) {
    if (col[u]) continue;
    rdfs(u, ++now);
  }

  for (int v = 0; v < n; ++v) {
    used[v] = false;
  }

  for (int v = 0; v < n; ++v) {
    if (used[v]) continue;
    order.clear();
    G = 0;
    sdfs(v);
    for (int x : order) {
      g[x] = G;
    }
  }

  cin >> q;
  for (int i = 0; i < q; ++i) {
    ll v, s, t;
    cin >> v >> s >> t;
    --v;
    t = __gcd(t, g[v]);
    if (s % t) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}