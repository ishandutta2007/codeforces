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
const int N=110000;
int head[N],np[N<<1],p[N<<1],id[N<<1],tot;
int n,m;
int c[N];
bool us[N];
int dep[N],fa[N],vis[N];
bool is=0;
int gtx,gty,gt;

int k[N];
LL b[N];
int a1[N];
LL a2[N];
//node is kx+b
void dd2(int x){
	vis[x]=1;
	for(int u=head[x];u;u=np[u])if(p[u]^fa[x])if(!vis[p[u]])if(id[u]!=gt)if(us[id[u]]){
		fa[p[u]]=x;
		dd2(p[u]);
		int nk=-k[p[u]];
		LL nb=c[p[u]]-b[p[u]];
		a1[id[u]]=nk;
		a2[id[u]]=nb;
		b[x]+=nb;
		k[x]+=nk;
	}
}

LL ans[N];
LL hav[N];
void dd(int x){
	for(int u=head[x];u;u=np[u])if(fa[p[u]]==x){
		dd(p[u]);
		ans[id[u]]=c[p[u]]-hav[p[u]];
		hav[x]+=ans[id[u]];
	}
}
void dfs(int x){
	vis[x]=1;
	for(int u=head[x];u;u=np[u])if(p[u]^fa[x]){
		if(vis[p[u]]){
			if(dep[p[u]]==dep[x]){
				is=1;
				gt=id[u];
				gtx=x;
				gty=p[u];
			}
		}
		else{
us[id[u]]=1;
			fa[p[u]]=x;
			dep[p[u]]=(dep[x]^1);
			dfs(p[u]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&c[i]);
	rep(i,1,m){
		int a,b;scanf("%d%d",&a,&b);
		++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;id[tot]=i;
		++tot;p[tot]=a;np[tot]=head[b];head[b]=tot;id[tot]=i;
	}
	dfs(1);
	if(!is){
		LL s=0;
		rep(i,1,n)if(dep[i])s+=c[i];
		else s-=c[i];
		if(s!=0){
			puts("NO");
			return 0;
		}
		dd(1);
		if(hav[1]!=c[1]){
			puts("NO");
			return 0;
		}
		puts("YES");
		rep(i,1,m)printf("%lld\n",ans[i]);
	}
	else{
		memset(fa,0,sizeof fa);
		memset(vis,0,sizeof vis);
		k[gty]=1;
		a1[gt]=1;
		//printf("%d %d %d\n",gt,gtx,gty);
		dd2(gtx);

		LL x=0;
		x=(c[gtx]-b[gtx])/2;
		puts("YES");
		rep(i,1,m)printf("%lld\n",x*a1[i]+a2[i]);
	}
	return 0;
}