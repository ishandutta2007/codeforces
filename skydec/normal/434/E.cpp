#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=210000;
vector<int>p[N];bool vis[N],inq[N];
int fa[N],froot[N],troot[N],size[N],q[N],powk[N],val[N],in0[N],out0[N],in1[N],out1[N],n,jsb,goal,k,dep[N],inv[N];
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%jsb)if(b&1)c=c*1ll*a%jsb;
	return c;
}
const int mo=1000007;
struct state{
	int head[N*10],np[N],p[N],cnt[N];int tot;
	inline void clear(){
		rep(i,1,tot){
			int x=p[i];np[i]=cnt[i]=p[i]=0;
			x%=mo;head[x]=0;
		}
		tot=0;
	}
	inline void add(int x){
		int pos=x%mo;
		for(int u=head[pos];u;u=np[u])if(p[u]==x){
			cnt[u]++;return;
		}
		tot++;p[tot]=x;cnt[tot]=1;np[tot]=head[pos];head[pos]=tot;
	}
	inline int ask(int x){
		int pos=x%mo;
		for(int u=head[pos];u;u=np[u])if(p[u]==x){
			return cnt[u];
		}
		return 0;
	}
}cnt;
inline int getroot(int y){
	q[q[0]=1]=y;inq[y]=1;fa[y]=0;
	rep(i,1,q[0]){
		int x=q[i];
		rep(j,0,p[x].size()-1)if(!inq[p[x][j]]&&!vis[p[x][j]]){
			q[++q[0]]=p[x][j];
			inq[p[x][j]]=1;
			fa[p[x][j]]=x;
		}
	}
	int a,b;b=210000;a=0;
	per(i,q[0],1){
		int x=q[i];
		size[x]=1;int MA=-1;
		rep(j,0,p[x].size()-1)if(inq[p[x][j]]&&fa[x]!=p[x][j]&&!vis[p[x][j]]){
			size[x]+=size[p[x][j]];
			if(size[p[x][j]]>MA)MA=size[p[x][j]];
		}
		if(q[0]-size[x]>MA)MA=q[0]-size[x];
		if(MA<b){
			b=MA;a=x;
		}
	}
	rep(i,1,q[0]){
		int x=q[i];inq[x]=0;
	}
	return a;
}
inline void Bfs1(int y){
	q[q[0]=1]=y;inq[y]=1;froot[y]=val[y];troot[y]=val[y];dep[y]=0;
	rep(i,1,q[0]){
		int x=q[i];
		rep(j,0,p[x].size()-1)if(!inq[p[x][j]]&&!vis[p[x][j]]){
			int d=p[x][j];
			troot[d]=(troot[x]*1ll*k+val[d])%jsb;
			dep[d]=dep[x]+1;
			froot[d]=(froot[x]+1ll*powk[dep[d]]*val[d])%jsb;
			q[++q[0]]=d;inq[d]=1;
		}
	}
	rep(i,1,q[0])inq[q[i]]=0;
}
inline void work(int rt,int y,int v){
	q[q[0]=1]=y;inq[y]=1;
	rep(i,1,q[0]){
		int x=q[i];
		rep(j,0,p[x].size()-1)if(!inq[p[x][j]]&&!vis[p[x][j]]){
			inq[p[x][j]]=1;
			q[++q[0]]=p[x][j];
		}
	}
	rep(i,1,q[0])cnt.add((froot[q[i]]+jsb)%jsb);
	rep(i,1,q[0]){
		int x=q[i];
		int key=powk[dep[x]]*1ll*val[rt]%jsb;
		key=(key+goal)%jsb;
		key=(key-troot[x])%jsb;
		key=key*1ll*inv[dep[x]]%jsb;
		if(key<0)key+=jsb;
		out1[x]+=cnt.ask(key)*v;
	}
	cnt.clear();
	
	rep(i,1,q[0]){
		int x=q[i];
		int key=(goal-troot[x])%jsb;
		key=key*1ll*inv[dep[x]]%jsb;
		if(key<0)key+=jsb;
		cnt.add(key);
	}
	
	rep(i,1,q[0]){
		int x=q[i];
		int key=froot[x];
		key=(key-val[rt])%jsb;
		if(key<0)key+=jsb;
		in1[x]+=cnt.ask(key)*v;
	}
	
	cnt.clear();
	
	rep(i,1,q[0])inq[q[i]]=0;
}
void fenzhi(int y,int depp){
	//assert(depp<=20);
	int x=getroot(y);
	Bfs1(x);vis[x]=1;
	work(x,x,1);
	rep(i,0,p[x].size()-1)if(!vis[p[x][i]])work(x,p[x][i],-1);
	rep(i,0,p[x].size()-1)if(!vis[p[x][i]])fenzhi(p[x][i],depp+1);
}
int main(){
	scanf("%d%d%d%d",&n,&jsb,&k,&goal);
	powk[0]=1;rep(i,1,n)powk[i]=powk[i-1]*1ll*k%jsb;
	rep(i,0,n)inv[i]=Pow(powk[i],jsb-2);
	rep(i,1,n)scanf("%d",&val[i]);
	rep(i,1,n-1){
		int u,v;scanf("%d%d",&u,&v);
		p[u].pb(v);p[v].pb(u);
	}
	fenzhi(1,0);
	LL ans=0;
	rep(i,1,n){
		in0[i]=n-in1[i];
		out0[i]=n-out1[i];
		ans=(ans+2ll*out1[i]*out0[i]);
		ans=(ans+2ll*in1[i]*in0[i]);
		ans=(ans+1ll*in1[i]*out0[i]);
		ans=(ans+1ll*in0[i]*out1[i]);
	}
	LL pa=n*1ll*n;
	pa=pa*1ll*n;
	ans/=2;
	printf("%I64d\n",pa-ans);
	return 0;
}