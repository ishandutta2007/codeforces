#include<bits/stdc++.h>
#define int long long
const int N=400050,P=19;
using namespace std;

int t,n,fa[P][N],dp[N],x,y,ans[N],sz[N],hd[N],S; 
struct edge{
	int to,nx;
}e[N];
void add(int fr,int to){
	e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}void clr(){
	S=0;
	for(int i=1;i<=n+1;i++)hd[i]=dp[i]=0,ans[i]=0;
	for(int i=1;i<=n;i++)for(int j=0;j<P;j++)fa[j][i]=0;
}
void dfs(int k,int f){
	fa[0][k]=f,dp[k]=dp[f]+1,sz[k]=1;
	for(int i=1;i<P;i++)fa[i][k]=fa[i-1][fa[i-1][k]];
	for(int i=hd[k];i;i=e[i].nx)
		if(e[i].to!=f)
			dfs(e[i].to,k),sz[k]+=sz[e[i].to];
}
int lca(int x,int y){
	if(dp[x]<dp[y])swap(x,y);
	for(int i=P-1;~i;i--)if(dp[fa[i][x]]>=dp[y])x=fa[i][x];
	if(x==y)return x;
	for(int i=P-1;~i;i--)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
int gf(int k,int x){
	for(int i=0,j=1;j<=x;i++,j<<=1)if(x&j)k=fa[i][k];
	return k;
}
int gs(int k,int f){
	return gf(k,dp[k]-dp[f]-1);
}
int calc(int l,int r,int f){
	if(dp[l]>dp[r])swap(l,r);
	if(f)return sz[l]*sz[r];
	else return (n-sz[gs(r,l)])*sz[r];
}


main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<n;i++)scanf("%lld%lld",&x,&y),add(x+1,y+1),add(y+1,x+1);
		dfs(1,0);
		int l=1,r=1,f=0,L=0;ans[1]=n*(n-1)/2,ans[2]=0;
		for(int i=hd[1],s=1;i;s+=sz[e[i].to],i=e[i].nx)
			ans[2]+=sz[e[i].to]*s;
		for(int i=2;i<=n;ans[i+1]=calc(l,r,f),i++)
			if(!f){
				int la=lca(r,i);
				if(la==r)r=i;
				else if(la==i){
					if(dp[la]<dp[l])l=la;
				}else if(dp[la]<=dp[l])l=i,f=1,L=la;
				else break;
			} else{
				int la=lca(r,i),lc=lca(l,i);
				if(la==r)r=i;
				else if(lc==l)l=i;
				else if(la==i&&dp[la]>=dp[L]);
				else if(lc==i&&dp[lc]>=dp[L]);
				else break;
			}
		for(int i=1;i<=n+1;i++)
			printf("%lld ",ans[i]-ans[i+1]);
		printf("\n");clr();
	}
}