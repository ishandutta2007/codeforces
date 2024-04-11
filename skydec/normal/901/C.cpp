#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=310000;
int head[N],np[N<<1],p[N<<1],tot;
int n,m,Q;
int sl[N],sr[N];
int k;

int fa[N];
bool instk[N];
bool vis[N];
int stk[N],t;
void dfs(int x){
	vis[x]=1;
	instk[x]=1;
	stk[++t]=x;
	for(int u=head[x];u;u=np[u])if(p[u]^fa[x]){
		if(!vis[p[u]]){
			fa[p[u]]=x;dfs(p[u]);
		}
		else{
			if(instk[p[u]]){
				int y=x;
				int mi=p[u];
				int ma=p[u];
				while(y!=p[u]){
					mi=min(mi,y);
					ma=max(ma,y);
					y=fa[y];
				}
				++k;
				sl[k]=mi;sr[k]=ma;
			}
		}
	}
	while(1){
		int v=stk[t--];
		instk[v]=0;
		if(v==x)break;
	}
}
int u[N];
LL sum[N];
int fd(int x){
	int l=1;
	int r=n;
	int ret=n+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(u[mid]>=x)ret=mid,r=mid;
		else l=mid+1;
	}
	if(u[l]>=x)ret=l;
	return ret;
}	
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int a,b;scanf("%d%d",&a,&b);
		if(a==b)continue;
		++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;
		++tot;p[tot]=a;np[tot]=head[b];head[b]=tot;
	}
	rep(i,1,n)if(!vis[i])dfs(i);

	rep(i,1,n)u[i]=1;
	rep(i,1,k)u[sr[i]]=max(u[sr[i]],sl[i]+1);
	rep(i,2,n)u[i]=max(u[i],u[i-1]);
	rep(i,1,n)sum[i]=sum[i-1]+u[i];

	scanf("%d",&Q);
	while(Q--){
		int x,y;scanf("%d%d",&x,&y);
		LL ans=((y+1)*1ll*(y+2)-x*1ll*(x+1))/2;
		int d=fd(x);
		if(d>y)ans-=(y-x+1)*1ll*x;
		else if(d<=x)ans-=sum[y]-sum[x-1];
		else{
			ans-=(d-1-x+1)*1ll*x;
			ans-=sum[y]-sum[d-1];
		}
		printf("%lld\n",ans);
	}
	return 0;
}