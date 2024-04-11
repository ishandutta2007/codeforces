#include <bits/stdc++.h>
using namespace std;

const int N = 100011;
using ll = long long;
struct Edge {
	int v; ll w;
};
vector <Edge> e[N];

ll pc[63];
const ll Mod = (ll)1e9 + 7;
const ll Inv2 = (Mod + 1) / 2;

vector <Edge> edges[N];
bool vis[N];
vector <ll> cycle;
ll path_xor[N];

vector <int> tv;
void dfs(int x) {
	vis[x] = true;
	tv.push_back(x);
	for(auto i : edges[x]) if(!vis[i.v]) {
		path_xor[i.v] = path_xor[x] ^ i.w;
		e[x].push_back({i.v, i.w});
		e[i.v].push_back({x, i.w});
		dfs(i.v);
	} else cycle.push_back(path_xor[x] ^ path_xor[i.v] ^ i.w);
}

ll lowbit(ll x) { return x & (-x); }

void gauss_insert(vector <ll> &v, ll x)
{
	/*
	for (auto j : G) if ((i ^ j) < i)
		i ^= j;
	if (i)
		G.push_back(i);
	sort(G.begin(), G.end(), greater<ll>());
	*/
	/*
	for(int i = 0; i < v.size(); i ++)
		if(v[i] & (-v[i]) & x)
			x ^= v[i];
	if(x == 0) return;
	for(int i = 0; i < v.size(); i ++)
		if(x & (-x) & v[i])
			v[i] ^= x;
	v.push_back(x);
	*/
	
	for(auto y : v)
		if(lowbit(y) & x)
			x ^= y;
	if(x == 0) return;
	for(auto &y : v)
		if(lowbit(x) & y)
			y ^= x;
	v.push_back(x);
	
	/*
	sort(v.begin(), v.end(), [](int a, int b) {
		return lowbit(a) < lowbit(b);
	});
	*/
}

int main() {
	ios :: sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i ++) {
		int u, v; ll w; cin >> u >> v >> w;
		edges[u].push_back(Edge{v, w});
		edges[v].push_back(Edge{u, w});
	}
	
	vector <vector <int> > comp;
	vector <vector <ll> > cb;
	for(int i = 1; i <= n; i ++) if(!vis[i]) {
		tv.clear();
		cycle.clear();
		dfs(i);
		comp.push_back(tv);
		cb.push_back(cycle);
	}

	ll ans = 0;

	for(int vid = 0; vid < comp.size(); vid ++) {
		memset(pc, 0, sizeof(pc));
		for(int j = 0; j < 63; j ++) {
			int c0 = 0, c1 = 0;
			for(int i : comp[vid]) {
				if((path_xor[i] >> j) & 1LL) {
					pc[j] += c0;
					c1 ++;
				} else {
					pc[j] += c1;
					c0 ++;
				}
			}
		}
		ll all = (ll)comp[vid].size() * (ll)(comp[vid].size() - 1) / 2;

		vector <ll> base;
		for(ll x : cb[vid])
			gauss_insert(base, x);
		/*
		if(m == 50000 && comp[vid].size() > 1) {
			cout << comp[vid].size() << '\n';
		}
		*/
		//for(int x : base) cout << x << '\n';
		ll mul = (1LL << base.size()) % Mod;
		for(int j = 0; j < 63; j ++) {
			bool f = false;
			for(ll x : base)
				if((x >> j) & 1LL) f = true;
			if(f)
				ans += all % Mod * ((1LL << j) % Mod) % Mod * mul % Mod * Inv2 % Mod;
			else
				ans += pc[j] % Mod * ((1LL << j) % Mod) % Mod * mul % Mod;
		}
	}

	cout << ans % Mod << '\n';
	return 0;
}