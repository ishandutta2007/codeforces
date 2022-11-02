#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 200006; 

int n, m, k; 
int r[maxn]; 
vi e[maxn]; 
vi g[maxn]; 
int q[maxn]; 
int d[maxn]; 
int tot;
int oud[maxn];  
int ans[maxn]; 
vi sur[maxn]; 
bool v[maxn]; 
set<pair<int,int>> S; 

void dfs(int x) {
	v[x] = true; 
	for (auto i : e[x]) 
		if (!v[i]) dfs(i); 
	q[++tot] = x; 
}


void Del(int x) {
	for (auto j : g[x]) {
		oud[j]--; 
		if (oud[j] == 0 && r[j] == 0) S.insert({d[j],j}); 
	}
	S.erase(make_pair(d[x],x)); 
}

int main() {
	scanf( "%d%d%d", &n, &m, &k ); 
	for (int i = 1; i <= n; ++i) {
		scanf( "%d", &r[i] ); 
		sur[r[i]].pb(i); 
	}
	for (int i = 1; i <= m; ++i) {
		int x, y; scanf( "%d%d", &x, &y ); 
		e[y].pb(x); 
		g[x].pb(y); 
	}
	memset(v, false, sizeof(v)); 
	tot = 0; 
	for (int i = 1; i <= n; ++i) 
		if (!v[i]) dfs(i); 	
	for (int i = 1; i <= n; ++i) d[i] = 1; 
	reverse(q+1, q+n+1); 
	for (int u = 1; u <= n; ++u) {
		int i = q[u]; 
		d[i] = max(d[i], r[i]); 
		for (auto j : e[i]) 
			d[j] = max(d[j], d[i] + 1); 
	}
	for (int i = 1; i <= n; ++i) 
		oud[i] = e[i].size();
	for (int i = 1; i <= n; ++i) 
		if (oud[i] == 0 && r[i] == 0) S.insert({d[i],i});
	for (int i = k; i >= 1; --i) {
		bool flag = false; 
		for (auto x : sur[i]) {
			flag = true; 
			ans[x] = i; 
			Del(x); 
		}
		while (!S.empty() && S.rbegin()->fir >= i) {
			flag = true; 
			int x = S.rbegin()->sec; 
			ans[x] = i; 
			Del(x); 
		}
		if (!flag) {
			if (S.empty()) {
				puts( "-1" );
				return 0; 
			}
			int x = S.rbegin()->sec; 
			ans[x] = i; 
			Del(x); 
		}
	}
	//for (int i = 1; i <= n; ++i) cout<<d[i]<<' '; puts( "" ); 
	//for (int i = 1; i <= n; ++i) cout<<ans[i]<<' '; puts( "" ); 
	for (int i = 1; i <= n; ++i) 
		if (!(ans[i] >= 1 && ans[i] <= k && (r[i] == 0 || ans[i] == r[i]))) {
			puts( "-1" ); 
			return 0; 
		}
	for (int i = 1; i <= n; ++i) 
		for (auto j : e[i]) 
			if (ans[i] >= ans[j]) {
				puts( "-1" ); 
				return 0; 			
			}
	set<int> ss; 
	for (int i = 1; i <= n; ++i) ss.insert(ans[i]); 
	if ((int)ss.size() != k) {
		puts( "-1" ); 
		return 0; 		
	}
	for (int i = 1; i <= n; ++i) printf( "%d ", ans[i] ); 
	puts( "" ); 
}