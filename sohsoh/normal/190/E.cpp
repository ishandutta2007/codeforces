#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, c;
vector<int> C[MAXN], adj[MAXN]; 
set<int> st;
bool vis[MAXN];

void BFS(int v) {
	queue<int> q;
	q.push(v);
	vis[v] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		C[c].push_back(v);

		stack<int> rm, tmp;
		for (int e : adj[v]) {
			if (vis[e]) continue;
			st.erase(e);
			tmp.push(e);
		}

		for (int e : st) {
			if (vis[e]) continue;
			rm.push(e);
			vis[e] = true;
			q.push(e);
		}

		while (!rm.empty()) st.erase(rm.top()), rm.pop();
		while (!tmp.empty()) st.insert(tmp.top()), tmp.pop();
	}

	c++;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) st.insert(i);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}

	for (int i = 1; i <= n; i++) if (!vis[i]) BFS(i);
	
	printf("%d \n", c);
	for (int i = 0; i < c; i++) {
		printf("%ld ", C[i].size());
		for (int e : C[i]) printf("%d ", e);
		printf("\n");
	}
	return 0;
}