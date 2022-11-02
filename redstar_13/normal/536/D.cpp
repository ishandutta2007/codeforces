#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<INT, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

#define NN 2020
const INT inf=0x3f3f3f3f3f3f3f3fLL;

INT dis[2][NN];
vector <pii> adj[NN];

void dijkstra(int u, int n, INT *dis){
	priority_queue <pii, vector <pii>, greater <pii> > q;
	
	for(int i=1; i<=n; i++) dis[i]=inf;
	q.push(pii(dis[u]=0, u));
	
	while(!q.empty()){
		auto p=q.top(); q.pop();
		if(p.x>dis[u=p.y]) continue;
		for(pii e : adj[u]){
			int v=e.y;
			if(dis[v]>dis[u]+e.x){
				dis[v]=dis[u]+e.x;
				q.push(pii(dis[v], v));
			}
		}
	}
}

int p[NN];
int A[2][NN], C[2];
int cnt[NN][NN];
INT sum[NN][NN];
INT dp[2][NN][NN];

INT ssum(int x1, int y1, int x2, int y2){
	return sum[x2][y2]-sum[x1][y2]-sum[x2][y1]+sum[x1][y1];
}

int scnt(int x1, int y1, int x2, int y2){
	return cnt[x2][y2]-cnt[x1][y2]-cnt[x2][y1]+cnt[x1][y1];
}

INT mn1[NN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	
	for(int i=1; i<=n; i++) gn(p[i]);
	
	for(int i=0; i<m; i++){
		int u, v, w; gn(u, v); gn(w);
		adj[u].pb(pii(w, v));
		adj[v].pb(pii(w, u));
	}
	
	dijkstra(s, n, dis[0]);
	dijkstra(t, n, dis[1]);
	
	for(int i=0; i<2; i++){
		vector <INT> arr;
		for(int j=1; j<=n; j++) arr.pb(dis[i][j]);
		sort(arr.begin(), arr.end());
		arr.resize(C[i]=unique(arr.begin(), arr.end())-arr.begin());
		for(int j=1; j<=n; j++) A[i][j]=upper_bound(arr.begin(), arr.end(), dis[i][j])-arr.begin();
	}
	
	for(int i=1; i<=n; i++){
		cnt[A[0][i]][A[1][i]]++;
		sum[A[0][i]][A[1][i]]+=p[i];
	}
	
	for(int i=1; i<=C[0]; i++) for(int j=1; j<=C[1]; j++){
		cnt[i][j]+=cnt[i][j-1]+cnt[i-1][j]-cnt[i-1][j-1];
		sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
	}
	
	for(int i=C[0]; i--; ){
		INT mn0=0;
		for(int j=C[1]; j--; ){
			dp[0][i][j]=dp[1][i][j]=-inf;
			if(scnt(i, j, C[0], j+1)) smin(mn0, ssum(i, j+1, C[0], C[1])+dp[0][i][j+1]);
			smax(dp[1][i][j], ssum(i, j, C[0], C[1])-mn0);
			if(scnt(i, j, i+1, C[1])) smin(mn1[j], ssum(i+1, j, C[0], C[1])+dp[1][i+1][j]);
			smax(dp[0][i][j], ssum(i, j, C[0], C[1])-mn1[j]);
		}
	}
	
	if(dp[0][0][0]<0) puts("Cry");
	else if(dp[0][0][0]>0) puts("Break a heart");
	else puts("Flowers");
	
	return 0;
}