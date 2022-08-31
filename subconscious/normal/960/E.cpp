#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define P 1000000007
#define N 200005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef long double ld;
int b[N],v[N<<1],f[N<<1],tot=0;
int dp[2][N],a[N],s[N];
int n,ans;
void add(int x,int y){v[++tot]=y,f[tot]=b[x],b[x]=tot;}
int x,y;
void dfs(int x,int fa){
	for(int i=b[x];i;i=f[i])
		if(v[i]!=fa)dfs(v[i],x),
		dp[0][x]+=dp[1][v[i]],
		dp[1][x]+=dp[0][v[i]];
	++dp[0][x];
}
void sol(int x,int fa,int s0,int s1){
	//int ss=ans;
	for(int i=b[x];i;i=f[i])
		if(v[i]!=fa)ans=(ans+1ll*a[x]*(dp[1][v[i]]-dp[0][v[i]]+P)%P*(n-dp[1][v[i]]-dp[0][v[i]]+P)%P)%P;
		else ans=(ans+1ll*a[x]*(s1-s0+P)%P*(dp[1][x]+dp[0][x])%P)%P;
	ans=(ans+1ll*a[x]*n%P)%P;
	//printf("%d\n",ans-ss);
	//printf("%d %d %d %d\n",x,fa,s0,s1);
	for(int i=b[x];i;i=f[i])if(v[i]!=fa){
		sol(v[i],x,dp[0][x]-dp[1][v[i]]+s1,dp[1][x]-dp[0][v[i]]+s0);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",a+i),a[i]=(a[i]+P)%P;
	rep(i,n-1)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	ans=0;dfs(1,0);sol(1,0,0,0);
	printf("%d\n",ans);
	return 0;
}