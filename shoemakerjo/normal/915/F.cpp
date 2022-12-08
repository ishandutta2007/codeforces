/**
* Sources: various
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define maxn 1000010

int par[maxn];
int mx[maxn];
int sp[maxn];
int sz[maxn];
int ra[maxn];
int vals[maxn];

const int MOD = 1000000007;

vector<vector<int>> adj;



int findset(int u) {
	if (par[u] == u) return u;
	return par[u] = findset(par[u]);
}

void unionSet(int u, int v) {
	u = findset(u);
	v = findset(v);
	int p = u;
	if (ra[v] > ra[u]) p = v;
	if (ra[u] == ra[v]) ra[p]++;
	par[u] = p;
	par[v] = p;
	if (mx[u] == mx[v]) {
		sp[p] = max(sp[u], sp[v]);
	}
	else if (mx[u] > mx[v]) {
		mx[p] = mx[u];
		sp[p] = sp[u];
	}
	else {
		mx[p] = mx[v];
		sp[p] = sp[v];
	}
	sz[p] = sz[v]+sz[u];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	vector<pii> nd;
	for (int i = 1; i <= n; i++) {
		cin >> vals[i];
		nd.pb(pii(vals[i], i));
	}
	for (int i = 0; i <= n; i++) {
		vector<int> bl;
		adj.pb(bl);
		par[i] = i;
		ra[i] = 1;
		mx[i] = vals[i];
		sp[i] = i;
		sz[i] = 1;
	}
	
	sort(nd.begin(), nd.end());
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	ll ans = 0LL;
	for (int i = 0; i < nd.size(); i++) {
		int vc = nd[i].first;
		int spot = nd[i].second;
		ll mult = 0LL;
		ll curin = 1LL;
		int sc = findset(spot);
		for (int j = 0; j < adj[spot].size(); j++) {
			sc = findset(spot);
			int u = adj[spot][j];
			u = findset(u);
			if (mx[sc] > mx[u]) {
				mult += curin*sz[u];
				curin += sz[u];
				unionSet(sc, u);
			}
			else if (mx[sc] == mx[u] && sp[sc] > sp[u]) {
				mult += curin*sz[u];
				curin += sz[u];
				unionSet(sc, u);
			}
		}
		sc = findset(spot);
		ll scur = sz[sc];
		// cout << "i   " << mult << "  " << vc << " " << spot <<  endl;
		ans += mult*(vc+0LL);
	}

	//do smallest here
	for (int i = 0; i <= n; i++) {
		
		par[i] = i;
		ra[i] = 1;
		mx[i] = 0-vals[i];
		sp[i] = i;
		sz[i] = 1;
	}
	
	nd.clear();
	for (int i = 1; i <= n; i++) {
		// cin >> vals[i];
		nd.pb(pii(0-vals[i], i));
	}
	sort(nd.begin(), nd.end());
	
	for (int i = 0; i < nd.size(); i++) {
		int vc = nd[i].first;
		int spot = nd[i].second;
		ll mult = 0LL;
		ll curin = 1LL;
		int sc = findset(spot);
		for (int j = 0; j < adj[spot].size(); j++) {
			sc = findset(spot);
			int u = adj[spot][j];
			u = findset(u);
			if (mx[sc] > mx[u]) {
				mult += curin*sz[u];
				curin += sz[u];
				unionSet(sc, u);
			}
			else if (mx[sc] == mx[u] && sp[sc] > sp[u]) {
				mult += curin*sz[u];
				curin += sz[u];
				unionSet(sc, u);
			}
		}
		sc = findset(spot);
		ll scur = sz[sc];
		// cout << "i   " << mult << "  " << vc << " " << spot <<  endl;
		ans += mult*(vc+0LL);
	}

	cout << ans << endl;
	cin >> ans;
}

//READ!READ!READ!READ!READ!READ!READ!READ!
//ll vs int!