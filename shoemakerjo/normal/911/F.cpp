#include <bits/stdc++.h>

using namespace std;
#define maxn 200010
#define INF 1000000

int n;
#define ll long long
vector<vector<int>> adj;
ll distf[maxn];

typedef pair<ll, ll> pii;
vector<pii> pa;
ll dist[maxn];
int fardist;
int farnode;
void dfs(int u, int p) {

	dist[u] = p == -1 ? 0: dist[p]+1;
	if (fardist < dist[u]) {
		fardist = dist[u];
		farnode = u;
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
	}
}

bool done;
int goal;

vector<int> di;
void sdfds(int u, int p) {
	if (u == goal) {
		di.push_back(u);
		done = true;
		return;
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		sdfds(v, u);
		if (done) {
			di.push_back(u);
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i <= n; i++) {
		vector<int> bl;
		adj.push_back(bl);
	}
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ll ans = 0LL;
	for (int i = 1; i <= n; i++) dist[i] = INF;
	farnode = 1;
	fardist = 0;
	dfs(1, -1);	
	// cout << "HERE" << endl;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	fardist = 0;
	int sn = farnode;
	dfs(farnode, -1);
	goal = farnode;
	sdfds(sn, -1);
	ans += ((di.size() + 0LL)*(di.size()-1LL))/2LL;
	for (int i = 1; i <= n; i++) {
		distf[i] = 0LL;
	}
	dfs(di[0], -1);
	int o[maxn];
	for (int i = 1; i <= n; i++) {
		distf[i] = max(distf[i], dist[i]);
		o[i] = di[0];
	}
	dfs(di[di.size()-1], -1);
	for (int i = 1; i <= n; i++) {
		if (dist[i] > distf[i]) o[i] = di[di.size()-1];
		distf[i] = max(distf[i], dist[i]);
		
	}
	for (int i = 0; i < di.size(); i++) {
		distf[di[i]] = 0LL;
		// cout << di[i] << " ";
		o[di[i]] = -1;
	}
	// cout << endl;
	for (int i = 1; i <= n; i++) {
		ans += distf[i];
	}
	cout << ans << endl;
	
	
	for (int i = 1; i <= n; i++) {
		if (o[i] == -1) continue;
		pa.push_back(pii(distf[i], i));
	}
	sort(pa.begin(), pa.end());
	reverse(pa.begin(), pa.end());
	for (int i = 0; i < pa.size(); i++) {
		cout << pa[i].second << " " << 
			o[pa[i].second] << " " << pa[i].second << endl;
	}
	for (int i = 0; i < di.size()-1; i++) {
		cout << di[i] << " " << di[di.size()-1] << " " << di[i] << endl;
	}
	// cout << ans << endl;
	cin >> ans;
}