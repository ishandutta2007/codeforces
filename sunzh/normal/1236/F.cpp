#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n,m;
vector<int>vec[500010],var[500010];
int degr[500010],in[500010],siz[500010];
int dep[500010],sum[500010],fa[500010];
int cnt;
const int mod=1000000007;
int a2,b2,c2,ac,ab,bc;
int a,b,c,qwq;
int qwq2;
int inv2,inv4,inv8,inv16;
int tag[500010];
int qpow(int x,int k){
	if(x==inv2&&tag[k]) return tag[k];
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	if(x==inv2) tag[k]=res;
	return res;
}
namespace solve1{
	void solve(){
		if(n&1) a=1ll*n%mod*inv2%mod;
		else a=n>>1;
//		printf("%d\n",a);
	}
}
namespace solve2{
	void solve(){
		b=1ll*m*inv4%mod;
//		printf("%d\n",b); 
	}
}
namespace solve3{
	void dfs(int x,int f){
		dep[x]=dep[f]+1;fa[x]=f;
		for(int i=0;i<vec[x].size();++i){
			int v=vec[x][i];
			if(v==f) continue ;
			if(dep[v]){
				if(dep[v]<dep[x]){
					int p=x;
					++cnt;
					while(p!=v){
						var[cnt].push_back(p);
						++siz[cnt];++in[p];p=fa[p];
					}
					var[cnt].push_back(v);
					++siz[cnt];++in[v];
				}
				else continue ;
			}
			else dfs(v,x);
		}
	}
	void solve(){
		dfs(1,1);
		for(int i=1;i<=cnt;++i) c+=qpow(inv2,siz[i]),c%=mod;
//		printf("%d\n",c);
	}
}
namespace solve4{
	void solve(){
		qwq=(a-b+c+mod)%mod;
//		printf("%d\n",qwq);
	}
}
namespace solve5{
	void solve(){
		a2=1ll*n*(n+1)%mod*inv4%mod;
//		printf("%d\n",a2);
	}
} 
namespace solve6{
	void solve(){
		b2=1ll*inv4*m%mod;
		int tot=m*(m-1);
		for(int i=1;i<=n;++i){
			tot-=degr[i]*(degr[i]-1);
			b2=(b2+degr[i]*(degr[i]-1)%mod*inv8%mod)%mod;
		}
		b2+=tot%mod*inv16%mod;
		b2%=mod;
//		printf("%d\n",b2%mod);
	}
}
namespace solve7{
	void solve(){
		for(int i=1;i<=cnt;++i){
			int res=qpow(inv2,siz[i]);
			for(int j=0;j<var[i].size();++j) sum[var[i][j]]=(sum[var[i][j]]+res)%mod;
		}
		for(int i=1;i<=cnt;++i){
			int tmp=qpow(inv2,siz[i]);
			int su=c-tmp;
			for(int j=0;j<var[i].size();++j){
				int p=var[i][j];
				c2=(c2+tmp*(sum[p]-tmp+mod)*2%mod)%mod;
				su=(su-(sum[p]-tmp)+mod)%mod;
			}
			c2=(c2+tmp*su%mod)%mod;
			c2=(c2+tmp)%mod;
		} 
//		printf("%d\n",c2);
	}
}
namespace solve8{
	void solve(){
		for(int i=1;i<=n;++i){
			ab=(ab+inv4*degr[i])%mod;
			ab=(ab+inv8*(m-degr[i]))%mod;
		}
//		printf("%d\n",ab);
	}
}
namespace solve9{
	void solve(){
		for(int i=1;i<=n;++i){
			ac=(ac+sum[i])%mod;
			ac=(ac+(c-sum[i])*inv2%mod)%mod;
		}
//		printf("%d\n",ac);
	}
}
namespace solve10{
	void solve(){
		for(int i=1;i<=cnt;++i){
			int lft=m-siz[i];
			int tmp=qpow(inv2,siz[i]);
			bc=(bc+tmp*siz[i]%mod)%mod;
			for(int j=0;j<var[i].size();++j){
				int p=var[i][j];
				bc=(bc+(degr[p]-2)*tmp%mod*inv2%mod)%mod;lft-=(degr[p]-2);
			}
			bc=(bc+tmp*lft%mod*inv4%mod)%mod;
		}
//		printf("%d\n",bc);
	}
}
namespace solve11{
	void solve(){
		qwq2=a2+b2+c2+(ac<<1)-(ab+bc<<1);
//		printf("%d\n",(qwq2%mod+mod)%mod);
	}
}
namespace solve12{
	void solve(){
		int ans=qwq2-qwq*qwq%mod;
		printf("%d\n",(ans%mod+mod)%mod);
	}
}
signed main(){
	inv2=qpow(2,mod-2);
	inv4=1ll*inv2*inv2%mod;
	inv8=1ll*inv2*inv4%mod;
	inv16=1ll*inv4*inv4%mod;
//	freopen("T2.in","r",stdin);
//	freopen("T2.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		vec[u].push_back(v);vec[v].push_back(u);
		++degr[u];++degr[v];
	}
	solve1::solve();
	solve2::solve();
	solve3::solve();
	solve4::solve();
	solve5::solve();
	solve6::solve();
	solve7::solve();
	solve8::solve();
	solve9::solve();
	solve10::solve();
	solve11::solve();
	solve12::solve();
}