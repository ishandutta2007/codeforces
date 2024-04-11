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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], tin[MAXN], n, T = 0, nxt[MAXN];
vector<ll> adj[MAXN];

void dfs(ll v, ll par = -1) {
	tin[v] = T;
	T--;
	for (ll u : adj[v]) if (u != par) dfs(u, v);
}

ll solve() {
	cin >> n;
	T = n + 1;
	fill(tin, tin + n + 10, -1);
	for (int i = 0; i < n + 10; i++) adj[i].clear();
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (A[i] == -1) A[i] = i + 2;
		A[i]--;
		adj[A[i]].push_back(i);
	}

	dfs(n);
	if (find(tin, tin + n, -1) != tin + n) return cout << -1 << endl, 0;
	
	stack<ll> st;
	for (int i = n; i >= 0; i--) {
		while (!st.empty() && tin[st.top()] < tin[i]) st.pop();
		if (st.empty()) nxt[i] = -1;
		else nxt[i] = st.top();
		st.push(i);
	}

	for (int i = 0; i < n; i++) if (nxt[i] != A[i]) return cout << -1 << endl, 0;
	for (int i = 0; i < n; i++) cout << tin[i] << sep;
	cout << endl;
	return 0;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}