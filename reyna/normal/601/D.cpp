//In the name of God
// (c) Silver soul 49
// What i'll engrave in this place is my soul!!!

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for(int i = (s); i < (e); i++)
#define x first
#define y second
#define int long long

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }


int pw (int a, int b, int mod) { return (b? pw(1LL * a * a % mod, b >> 1, mod) * 1LL * (b & 1? a : 1) % mod: 1); }
int lcm (int x, int y) { return min(x, y)? x / __gcd(x, y) * y: max(x, y); }

/*******************************************************************************************************/

const int maxN = 3e5 + 49;
const int base1 = 1000 * 1000 + 3;
const int base2 = 727;
const int mod1 = 1e9 + 7;
const int mod2 = 98765431;
const int oo = 1e9 + 49;

char s[maxN];

int sz[maxN], dep[maxN], pw1[maxN], pw2[maxN], h1[maxN], h2[maxN], val1[maxN], val2[maxN], tp1, tp2, dif[maxN], c[maxN];
set<pii> st;
vector<int> adj[maxN];

void dfs_init(int v, int p = -1) {
	sz[v] = 1;
	dep[v] = (p == -1? 0: dep[p] + 1);
	val1[v] = (s[v] * pw1[dep[v]]) % mod1;
	val2[v] = (s[v] * pw2[dep[v]]) % mod2;
	h1[v] = (p == -1? val1[v]: (val1[v] + h1[p]) % mod1);
	h2[v] = (p == -1? val2[v]: (val2[v] + h2[p]) % mod2);
	for (int u : adj[v]) if (u != p) {
		dfs_init(u, v);
		sz[v] += sz[u];
	}
}

void dfs_add(int v, int root, int p = -1) {
	st.insert({(h1[v] - h1[root] + val1[root] + mod1 + mod1 - tp1) % mod1, (h2[v] - h2[root] + val2[root] + mod2 + mod2 - tp2) % mod2});
	for (int u : adj[v]) if (u != p)
		dfs_add(u, root, v);
}


void go(int v, int p = -1) {
	int id = -1;
	for (int u : adj[v]) if (u != p) {
		if (id == -1 || sz[id] < sz[u])
			id = u;
	}
	for (int u : adj[v]) if (u != p && u != id) {
		go(u, v);
		tp1 = tp2 = 0;
		st.clear();
	}
	if (id != -1) {
		go(id, v);
		tp1 = (tp1 + val1[v]) % mod1;
		tp2 = (tp2 + val2[v]) % mod2;
	}
	for (int u : adj[v]) if (u != p && u != id)
		dfs_add(u, v, v);
	st.insert({(val1[v] + mod1 + mod1 - tp1) % mod1, (val2[v] + mod2 + mod2 - tp2) % mod2});
	dif[v] = (int) st.size();
}


int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < maxN; i++) pw1[i] = (i? pw1[i - 1] * base1 % mod1: 1), pw2[i] = (i? pw2[i - 1] * base2 % mod2: 1);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	cin >> s;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs_init(0);
	go(0);
	int mx = 0;
	for (int i = 0; i < n; i++)
		smax(mx, dif[i] + c[i]);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += ((dif[i] + c[i]) == mx);
	cout << mx << endl << cnt << endl;
}