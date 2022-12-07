#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 1000005
using namespace std;
typedef long long ll;
int b[N],v[N],c[N],f[N],tot;
int n,m,s,x,y,z;
void add(int x,int y,int z){v[++tot]=y;f[tot]=b[x];c[tot]=z;b[x]=tot;}
int dfn[N],low[N],cnt;
int sta[N],col[N],top,scc;bool in[N];
void tarjan(int x){
	dfn[x]=low[x]=++cnt;
	in[x]=1;sta[++top]=x;
	for(int i=b[x];i;i=f[i])
		if(!dfn[v[i]])tarjan(v[i]),low[x]=min(low[x],low[v[i]]);
		else if(in[v[i]])low[x]=min(low[x],dfn[v[i]]);
	if(dfn[x]==low[x]){
		in[x]=0;col[x]=++scc;
		while(sta[top]!=x){
			col[sta[top]]=scc;
			in[sta[top--]]=0;
		}
		--top;
	}
}
ll dp[N],is[N];
ll calc(int x){
	int l=0,r=30000;
	while(l+1<r){
		int mid=l+r>>1;
		if(1ll*mid*(mid+1)/2<=1ll*x)l=mid;else r=mid;
	}
	return 1ll*(l+1)*x-1ll*l*(l+1)*(l+2)/6;
}
int B[N],V[N],C[N],F[N],TOT;
void ADD(int x,int y,int z){V[++TOT]=y;C[TOT]=z;F[TOT]=B[x];B[x]=TOT;}
void sol(int x){
	if(dp[x]!=-1)return;
	dp[x]=is[x];
	for(int i=B[x];i;i=F[i])sol(V[i]),dp[x]=max(dp[x],is[x]+dp[V[i]]+C[i]);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,m)scanf("%d%d%d",&x,&y,&z),add(x,y,z);
	scanf("%d",&s);
	rep(i,n)if(!dfn[i])tarjan(i);
	rep(i,n)for(int j=b[i];j;j=f[j])if(col[i]==col[v[j]])is[col[i]]+=calc(c[j]);
	else ADD(col[i],col[v[j]],c[j]);
	rep(i,n)dp[i]=-1;
	sol(col[s]);
	printf("%I64d\n",dp[col[s]]);
	return 0;
}