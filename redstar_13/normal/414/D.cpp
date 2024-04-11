#include<bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long INT;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

#define NN 100100

vector<int> adj[NN];
int num[NN];

inline void dfs(int u, int fa=0, int dp=0) {
	if(dp++) num[dp]++;
	for(int v: adj[u]) if(v!=fa) dfs(v, u, dp);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, k, p; scanf("%d %d %d", &n, &k, &p);
	for(int i=1, u, v; i<n; i++) {
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	
	INT sum=0, money=0;
	int ans=0;
	
	for(int st=n, ed=n; ed; ed--) {
		while(st && money+(INT)(ed-st)*num[st]<=p) {
			money+=(INT)(ed-st)*num[st];
			sum+=num[st--];
		}
		
		smax(ans, sum+min((INT)num[st], (p-money)/(ed-st)));
		sum-=num[ed];
		money-=sum;
	}
	smin(ans, k);
	printf("%d", ans);
}