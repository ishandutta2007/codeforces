//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, dp1[N], dp2[N];
vector<tuple<int, int> > e[N];
vector<int> ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs1(int u, int f) {
	for(auto i : e[u]) {
		int v = get<0>(i), w = get<1>(i);
		if(v == f) continue;
		dfs1(v, u);
		dp1[u] += dp1[v] + w;
	}
}
void dfs2(int u, int f, int w) {
	if(!f) dp2[u] = dp1[u];
	else dp2[u] = dp2[f] + (w ? -1 : 1);
	for(auto i : e[u]) {
		int v = get<0>(i), w = get<1>(i);
		if(v == f) continue;
		dfs2(v, u, w); 
	}
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].emplace_back(v, 0);
		e[v].emplace_back(u, 1);
	}
	dfs1(1, 0);
	dfs2(1, 0, 0);
	int mn = n;
	rep(i, 1, n) {
		if(dp2[i] < mn) {
			mn = dp2[i];
			ans.clear();
			ans.push_back(i);
		}
		else if(dp2[i] == mn) ans.push_back(i);
	}
	printf("%d\n", mn);
	for(int i : ans) printf("%d ", i);
	puts("");
	return 0;
}