#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, in_deg[MAXN], in_cyc[MAXN], ans, C, A[MAXN];
vector<int> adj[MAXN], cyc[MAXN], n_cyc[MAXN];
bool vis[MAXN], L[MAXN];

void dfs(int v) {
	vis[v] = true;
	if (!L[v]) cyc[C].push_back(v);
	else if (in_deg[v] == 0) n_cyc[C].push_back(v);
	
	for (int u : adj[v])
		if (!vis[u])
			dfs(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		A[i] = x;
		in_deg[x]++, in_cyc[x]++;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (in_cyc[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int v = q.front();
		q.pop();	
		L[v] = true;
		in_cyc[A[v]]--;
		if (in_cyc[A[v]] == 0) q.push(A[v]);
	}

	vector<pll> ans;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		C++;
		dfs(i);
		while (n_cyc[C].size() > 1) {
			ans.push_back({cyc[C].back(), n_cyc[C].back()});
			n_cyc[C].pop_back();
		}
		
		if (C > 1) {
			int v = cyc[C].back();
			if (!n_cyc[C].empty()) {
				v = n_cyc[C].back();
				n_cyc[C].pop_back();
			}

			ans.push_back({cyc[C - 1].back(), v});
		}
	}
	
	if (C == 1) {
		while (!n_cyc[C].empty()) {
			ans.push_back({cyc[C].back(), n_cyc[C].back()});
			n_cyc[C].pop_back();
		}	
	} else {
		int v = cyc[1].back();
		if (!n_cyc[1].empty()) v = n_cyc[1].back();
		ans.push_back({cyc[C].back(), v});
	}

	cout << ans.size() << endl;
	for (pll e : ans) cout << e.X << sep << e.Y << endl;
	return 0;
}