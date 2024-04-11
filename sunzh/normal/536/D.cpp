#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
int s,t;
int p[2010];
int dis[2][2010];
int dp[2][2010][2010];
int a[2010];
vector<PII>vec[2010];
void dij1(){
	memset(dis[0],0x3f,sizeof(dis[0]));
	priority_queue<PII,vector<PII>,greater<PII> >Q;
	Q.push(mp(0,s));dis[0][s]=0;
	while(!Q.empty()){
		PII nw=Q.top();Q.pop();
		if(nw.fi!=dis[0][nw.se]) continue ;
		int u=nw.se;
		for(PII i:vec[u]){
			int v=i.fi,w=i.se+dis[0][u];
			if(dis[0][v]>w){
				dis[0][v]=w;Q.push(mp(w,v));
			}
		}
	}
	for(int i=1;i<=n;++i) a[i]=dis[0][i];
	sort(a+1,a+n+1);
	// for(int i=1;i<=n;++i) printf("%d ",dis[0][i]);printf("\n");
	for(int i=1;i<=n;++i) dis[0][i]=lower_bound(a+1,a+n+1,dis[0][i])-a;
}
void dij2(){
	memset(dis[1],0x3f,sizeof(dis[1]));
	priority_queue<PII,vector<PII>,greater<PII> >Q;
	Q.push(mp(0,t));dis[1][t]=0;
	while(!Q.empty()){
		PII nw=Q.top();Q.pop();
		if(nw.fi!=dis[1][nw.se]) continue ;
		int u=nw.se;
		for(PII i:vec[u]){
			int v=i.fi,w=i.se+dis[1][u];
			if(dis[1][v]>w){
				dis[1][v]=w;Q.push(mp(w,v));
			}
		}
	}
	for(int i=1;i<=n;++i) a[i]=dis[1][i];
	sort(a+1,a+n+1);
	// for(int i=1;i<=n;++i) printf("%d ",dis[1][i]);printf("\n");
	for(int i=1;i<=n;++i) dis[1][i]=lower_bound(a+1,a+n+1,dis[1][i])-a;
}
int sum1[2010][2010],sum2[2010][2010],siz1[2010][2010],siz2[2010][2010];
signed main(){
	n=read(),m=read();
	s=read(),t=read();
	for(int i=1;i<=n;++i) p[i]=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		vec[u].pb(mp(v,w));vec[v].pb(mp(u,w));
	}
	dij1();dij2();
	for(int i=1;i<=n;++i){
		// printf("i:%d,%d %d\n",i,dis[0][i],dis[1][i]);
		sum1[dis[0][i]][dis[1][i]]+=p[i];
		sum2[dis[0][i]][dis[1][i]]+=p[i];
		siz1[dis[0][i]][dis[1][i]]++;
		siz2[dis[0][i]][dis[1][i]]++;
	}
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j) {
			if(j) sum1[i][j]=sum1[i][j]+sum1[i][j-1];
			if(i) sum2[i][j]=sum2[i][j]+sum2[i-1][j];
			if(j) siz1[i][j]=siz1[i][j]+siz1[i][j-1];
			if(i) siz2[i][j]=siz2[i][j]+siz2[i-1][j];
		}
	}
	for(int i=n;i>=0;--i){
		for(int j=n;j>=0;--j){
			if(siz1[i+1][n]-siz1[i+1][j]>0) dp[0][i][j]=max(dp[0][i+1][j],dp[1][i+1][j])+sum1[i+1][n]-sum1[i+1][j];
			else dp[0][i][j]=dp[0][i+1][j];
			if(siz2[n][j+1]-siz2[i][j+1]>0) dp[1][i][j]=min(dp[1][i][j+1],dp[0][i][j+1])-sum2[n][j+1]+sum2[i][j+1];
			else dp[1][i][j]=dp[1][i][j+1];
			// printf("i:%d,j:%d,%d %d\n",i,j,dp[0][i][j],dp[1][i][j]);
		}
	}
	// printf("%lld\n",dp[0][0][0]);
	printf(dp[0][0][0]>0?"Break a heart\n":(dp[0][0][0]==0?"Flowers\n":"Cry\n"));
}