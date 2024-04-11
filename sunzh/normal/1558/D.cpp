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
#include<chrono>
#include<random>
using namespace std;
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rnd(SEED);
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n,m;
int fac[400010],ifac[400010];
const int mod=998244353;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int rt,cnt;
int son[400010][2];//int rnd[400010];
int siz[400010],val[400010],tag[400010],sum[400010],typ[400010];
void update(int p){
	sum[p]=sum[son[p][0]]+sum[son[p][1]]+typ[p];
	siz[p]=siz[son[p][0]]+siz[son[p][1]]+1;
}
void pushdown(int p){
	if(tag[p]){
		if(son[p][0]) tag[son[p][0]]+=tag[p],val[son[p][0]]+=tag[p];
		if(son[p][1]) tag[son[p][1]]+=tag[p],val[son[p][1]]+=tag[p];
		tag[p]=0;
	}
}
int merge(int x,int y){
	if(!x) return y;
	if(!y) return x;
	int rd=rnd()%(siz[x]+siz[y]);
	if(rd<siz[x]){
		pushdown(x);
		son[x][1]=merge(son[x][1],y);
		update(x);
		return x;
	}
	else{
		pushdown(y);
		son[y][0]=merge(x,son[y][0]);
		update(y);
		return y;
	}
}
void split(int now,int v,int &x,int &y){
	if(now==0){
		x=y=0;
		return ;
	}
	pushdown(now);
	if(val[now]<v)	x=now,split(son[now][1],v,son[now][1],y);
	else y=now,split(son[now][0],v,x,son[now][0]);
	update(now);
}
int new_node(int x,int tp){
	int now=++cnt;
	siz[now]=1,val[now]=x;tag[now]=0;typ[now]=sum[now]=tp;son[now][0]=son[now][1]=0;
	return now;
}
int C(int x,int y){
	if(x<y) return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int main(){
	fac[0]=1;
	for(int i=1;i<=400000;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[400000]=qpow(fac[400000]);
	for(int i=399999;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	// srand(time(0));
	T=read();
	while(T--){
		n=read(),m=read();cnt=0;rt=0;
		for(int i=1;i<=m;++i){
			int x=read(),y=read();
			int a=0,b=0;
			split(rt,y,a,b);
			if(b) tag[b]++,val[b]++;
			// printf("i:%d\n",i);
			// printf("a:%d,b:%d\n",a,b);
			// printf("%d %d\n",val[a],val[b]);
			b=merge(new_node(y,1),b);
			int c=0;
			split(a,y-1,a,c);
			if(c){
				typ[c]=sum[c]=0;
			}
			rt=merge(merge(a,c),b);
		}
		// printf("cnt:%d\n",cnt);
		int t=sum[rt];
		// printf("t:%d\n",t);
		int ans=0;
		ans=C(n-t+n-1,n);
		// for(int i=1;i+t<=n;++i){
		// 	(ans+=C(n-t-i+n-1,n-1))%=mod;
		// }
		printf("%d\n",ans);
	}
}