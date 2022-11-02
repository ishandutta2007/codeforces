#include<bits/stdc++.h>
#define Sz(xx) t[xx].size()
#define upd(xx) for(;f[xx]^xx;xx=f[xx])
const int N=500005;
using namespace std;
int n,m,al,u,v;
char op[3];
long long va[N],ans;
struct T{
	int f[N],sz[N],ui[N];
	vector<int>t[N];
	inline void push(){
		upd(u);
		va[al]=sz[u]+(Sz(u)?va[t[u][Sz(u)-1]]:0);
		t[u].push_back(al);
	}
	inline void uni(){
		upd(u);upd(v);
		if(sz[u]<sz[v])swap(u,v);
		sz[f[v]=u]+=sz[v];
		ui[v]=Sz(u);
	}
	inline void get(int u){
		int tp=0;
		for(;;tp=ui[u],u=f[u]){
			if(Sz(u)>tp)v=t[u][Sz(u)-1];
			if(f[u]==u)break;
		}
	}
	inline void sol(){
		int tp=0,re;
		for(;;tp=ui[u],u=f[u]){
			if(Sz(u)>tp&&t[u][Sz(u)-1]>v){
				ans+=va[t[u][Sz(u)-1]];
				if(t[u][tp]<v){
					re=tp-1;
					for(int l=tp,r=Sz(u)-1,mi;l<=r;)
					if(t[u][mi=l+r>>1]<v)
					re=mi,l=mi+1;else r=mi-1;
					ans-=va[t[u][re]];
				}
				else if(tp)ans-=va[t[u][tp-1]];
			}
		if(f[u]==u)break;
		}
	}
}A,D;
int main(){
	//freopen("dat.txt","r",stdin);
	//freopen("me.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	A.f[i]=D.f[i]=i,
	A.sz[i]=D.sz[i]=1;
	for(al=1;al<=m;al++){
		scanf("%s%d",op,&u);
		if(op[0]=='A')A.push();
		else if(op[0]=='Z')D.push();
		else if(op[0]=='Q'){
			v=ans=0;
			D.get(u);
			//cerr<<"clear before "<<v<<endl;
			A.sol();
			printf("%lld\n",ans);
		}
		else scanf("%d",&v),
		op[0]^'U'?D.uni():A.uni();
	}
}