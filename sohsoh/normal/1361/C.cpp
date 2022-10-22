#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 1e5;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<pll> v;
vector<ll> adj[MAXN], K[MAXN];
bool vis[MAXN] = {false};

void dfs(ll v) {
	vis[v] = true;
	for (ll u : adj[v]) if (!vis[u]) dfs(u);
}

bool check_euler(ll mx) {
	bool used = false;
	for (int i = 0; i <= mx; i++) {
		if (ll(adj[i].size()) & 1) return false;
	       	if (!vis[i] && adj[i].size()) {
			if (used) return false;
			dfs(i);
			used = true;
		}	
	}

	return true;
}

map<pll, vector<pll>> mp;

stack<ll> st;
multiset<ll> adj2[MAXN];
void euler_dfs(ll v) {
	while (!adj2[v].empty()) {
		ll u = *adj2[v].begin();
		adj2[v].erase(adj2[v].begin());
		adj2[u].erase(adj2[u].find(v));	
		euler_dfs(u);	
	}

	st.push(v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		pll x;
		cin >> x.X >> x.Y;
		v.push_back(x);
	}

	for (int ans = 20; ans >= 0; ans--) {
		ll msk = (1 << ans) - 1, ind = 1;
		for (int i = 0; i < msk + 10; i++) adj[i].clear(), vis[i] = false;	
		for (pll e : v) {
			ll u = e.X & msk, v = e.Y & msk;
			adj[u].push_back(v);
			adj[v].push_back(u);
			ind++;
		}	

		if (!check_euler(msk)) continue; //
		cout << ans << endl;
		ll s = 0;
		for (int i = 0; i <= msk; i++) for (ll u : adj[i]) adj2[i].insert(u), s = i;
	
		ind = 1;	
		for (pll e : v) {
			ll u = e.X & msk, v = e.Y & msk;
			ll x = 2 * ind - 1, y = 2 * ind;
			mp[make_pair(u, v)].push_back({x, y});	
			mp[make_pair(v, u)].push_back({y, x});	
			ind++;
		}
		
		euler_dfs(s);
		vector<ll> trv;
		while (!st.empty()) trv.push_back(st.top()), st.pop();
		vector<ll> f_ans;
		for (int i = 0; i < trv.size() - 1; i++) {
			ll v = trv[i], u = trv[i + 1];
			auto it = mp.find({v, u});
			if (it != mp.end()) {
				f_ans.push_back(it -> Y.back().X);
				f_ans.push_back(it -> Y.back().Y);
				it -> Y.pop_back();
				mp.find({u, v}) -> Y.pop_back(); 
			}
		}

		for (ll u : f_ans) cout << u << sep;
		cout << endl;
		break;
	}
	return 0;
}