#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

#define x first
#define y second
#define pb push_back

int power(int a, int b, int c, int ans=1) {
	for (; b; b>>=1, a=(INT)a*a%c) if (b&1) ans=(INT)ans*a%c;
	return ans;
}

const int NN = 200011;
vector<pii> edge;
int n, m;
VI adj[NN];
VI vec;
int vst[NN];
int cst[NN];

int s, t;
int cut;
int cc;
int cnt[NN];

void dfs(int u) {
	if(u!=s and u!=t) vec.pb(u);
	vst[u] = cc;
	for(int v : adj[u]) if(v != cut and vst[v] == 0) dfs(v);
}

int solve() {
	edge.clear();
	cc = 0;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(int i=1; i<=n; i++) vst[i] = cnt[i] = 0, adj[i].clear();
	for(int i=0; i<m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	cut = s;
	INT ans = 0;
	for(int i=1; i<=n; i++) if(vst[i] == 0 and i!=s and i!=t) {
		vec.clear();
		cc++, dfs(i);
		ans += (INT)vec.size() * (n-2-(int)vec.size());
	}
	
	cut = t;
	for(int i=1; i<=n; i++) cst[i] = vst[i], vst[i] = 0;
	cc = 0;
	for(int i=1; i<=n; i++) if(vst[i] == 0 and i!=s and i!=t) {
		vec.clear();
		cc++, dfs(i);
		sort(vec.begin(), vec.end(), [](int u, int v) {
			return cst[u] < cst[v];
		});
		int m=vec.size();
		for(int j=0, k=0; j<m; j=k) {
			while(k<m and cst[vec[j]] == cst[vec[k]]) k++;
			ans -= (INT)(k-j) * (m-k+j);
		}
	}
	cout << ans/2<<endl;
	
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int T;
	cin >> T;
	while(T--) solve();

	return 0;
}