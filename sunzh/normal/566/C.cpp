#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define ep emplace_back
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
int d[200010];
vector<PII>vec[200010];
int rt,sm;
int mx[200010];
int siz[200010];
bool vis[200010];
long double sum;
long double Sum,F[200010];
int ans1;
long double ans2;
void calc(int x,int fa,int fx,int dep){
	sum+=d[x]*powl(dep,1.5L);
	F[fx]+=1.5*d[x]*powl(dep,0.5L);
	for(auto i:vec[x]){
		int v=i.fi;
		if(v==fa) continue ;
		calc(v,x,fx,dep+i.se);
	}
}
void getsiz(int x,int fa){
	siz[x]=1;
	for(auto i:vec[x]){
		int v=i.fi;
		if(vis[v]||v==fa) continue ;
		getsiz(v,x);siz[x]+=siz[v];
	}
}
void getrt(int x,int fa){
	mx[x]=0;
	for(auto i:vec[x]){
		int v=i.fi;
		if(vis[v]||v==fa) continue ;
		getrt(v,x);
		mx[x]=max(mx[x],siz[v]);
	}
	mx[x]=max(mx[x],sm-siz[x]);
	if(mx[x]<mx[rt]) rt=x;
}
void solve(int x){
	vis[x]=1;
	sum=Sum=0.0L;
	for(auto i:vec[x]){
		int v=i.fi;
//		if(vis[v]) continue ;
		F[v]=0.0L;
		calc(v,x,v,i.se);Sum+=F[v];
	}
//	printf("x:%d,%.6Lf\n",x,sum);
	if(sum<ans2) ans1=x,ans2=sum;
	for(auto i:vec[x]){
		int v=i.fi;
		if(vis[v]) continue ;
		if(Sum-2*F[v]<0.0L){
			sm=siz[v];
			getsiz(v,x);
			rt=0;
			getrt(v,x);
			solve(rt);
			break ;
		}
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) d[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read(),w=read();
		vec[u].ep(v,w);vec[v].ep(u,w);
	}
	sm=n;mx[0]=0x3f3f3f3f;
	getsiz(1,0);
	getrt(1,0);
	ans1=-1,ans2=1e25;
//	printf("rt:%d\n",rt);
	solve(rt);
	printf("%d %.10Lf\n",ans1,ans2);
}