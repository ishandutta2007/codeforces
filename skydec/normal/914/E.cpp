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
const int N=210000;
int head[N],np[N<<1],p[N<<1],tot;
int n;
char _str[N];
int col[N];
int fa[N],size[N];
bool vis[N],inq[N];
int q[N];
LL ans[N];
int getRoot(int ss){
	q[q[0]=1]=ss;
	inq[ss]=1;
	rep(i,1,q[0]){
		int x=q[i];
		for(int u=head[x];u;u=np[u])if(!vis[p[u]])if(!inq[p[u]]){
			fa[p[u]]=x;
			q[++q[0]]=p[u];
			inq[p[u]]=1;
		}
	}
	int mi=1000000;
	int rp=0;
	per(i,q[0],1){
		int x=q[i];
		int ma=-1;
		size[x]=1;
		for(int u=head[x];u;u=np[u])if(!vis[p[u]])if(inq[p[u]])if(fa[p[u]]==x){
			size[x]+=size[p[u]];
			ma=max(ma,size[p[u]]);
		}
		ma=max(ma,q[0]-size[x]);
		if(ma<mi){
			mi=ma;
			rp=x;
		}
	}
	rep(i,1,q[0]){
		int x=q[i];
		size[x]=fa[x];inq[x]=0;
	}
	q[0]=0;
	return rp;
}
int val[N];
void bfs1(int rt){
	q[q[0]=1]=rt;
	inq[rt]=1;
	val[rt]=(1<<col[rt]);

	rep(i,1,q[0]){
		int x=q[i];
		for(int u=head[x];u;u=np[u])if(!inq[p[u]])if(!vis[p[u]]){
			fa[p[u]]=x;
			inq[p[u]]=1;
			val[p[u]]=val[x]^(1<<col[p[u]]);
			q[++q[0]]=p[u];
		}
	}
}
int pp[1<<20];
int ti[1<<20];
int cnt[1<<20];
int nowt;
int meask(int t){
	if(ti[t]!=nowt){
		pp[t]=0;
		ti[t]=nowt;
	}
	return pp[t];
}
void meadd(int t,int v){
	if(ti[t]!=nowt){
		pp[t]=0;
		ti[t]=nowt;
	}
	pp[t]+=v;
}
LL res=0;
LL sb[N];
void dfs1(int x,int ff){
	sb[x]=0;
	if(cnt[val[x]]<=1)++sb[x];
	//if(ff==2&&x==6)printf("____________%d\n",sb[x]);
	for(int u=head[x];u;u=np[u])if(p[u]!=ff)if(inq[p[u]])if(fa[p[u]]==x)if(!vis[p[u]]){
		dfs1(p[u],x);
		sb[x]+=sb[p[u]];
	}
	ans[x]+=sb[x];
}
int nowcol;
void calc1(int x,int ff=-1){
	sb[x]=meask(val[x]^(1<<nowcol));
	rep(i,0,19){
		int ot=(val[x]^(1<<nowcol));
		ot^=(1<<i);
		sb[x]+=meask(ot);
	}
	for(int u=head[x];u;u=np[u])if(p[u]!=ff)if(inq[p[u]])if(fa[p[u]]==x)if(!vis[p[u]]){
		calc1(p[u],x);
		sb[x]+=sb[p[u]];
	}
	ans[x]+=sb[x];
}
void add1(int x,int ff=-1){
	meadd(val[x],1);
	for(int u=head[x];u;u=np[u])if(p[u]!=ff)if(inq[p[u]])if(fa[p[u]]==x)if(!vis[p[u]]){
		add1(p[u],x);
	}
}
int xp[N];
void work(int ss){
	int rt=getRoot(ss);
	vis[rt]=1;
	bfs1(rt);
	nowt=rt;
	nowcol=col[rt];
	//root to it
	res=0;
	dfs1(rt,-1);
	xp[0]=0;
	//rep(i,1,n)printf(".%d:%lld\n",i,ans[i]);
	for(int u=head[rt];u;u=np[u])if(!vis[p[u]])if(inq[p[u]]){
		calc1(p[u]);
		add1(p[u]);
		xp[++xp[0]]=p[u];
		ans[rt]+=sb[p[u]];
	}
	nowt=n+rt;
	per(i,xp[0],1){
		int x=xp[i];
		calc1(x);
		add1(x);
	}
	//rep(i,1,n)printf("%d:%lld\n",i,ans[i]);
	//rep(i,1,n)printf("_%d:%d\n",i,val[i]);
	rep(i,1,q[0]){
		int x=q[i];
		fa[x]=0;
		inq[x]=0;
		val[x]=0;
		size[x]=0;
	}
	q[0]=0;
	for(int u=head[rt];u;u=np[u])if(!vis[p[u]])work(p[u]);
}
int main(){
	rep(i,1,(1<<20)-1)cnt[i]=cnt[i>>1]+(i&1);
	scanf("%d",&n);
	rep(i,1,n-1){
		int a,b;scanf("%d%d",&a,&b);
		++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;
		++tot;p[tot]=a;np[tot]=head[b];head[b]=tot;
	}
	scanf("%s",_str+1);
	rep(i,1,n)col[i]=_str[i]-'a';

	work(1);
	rep(i,1,n)printf("%lld%c",ans[i],i==n?'\n':' ');
	return 0;
}