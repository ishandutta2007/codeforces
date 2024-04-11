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
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
const int mod=1e9+7;
int T;
int n;
int a[200010];
int pr[200010],sf[200010],fx[200010];
struct BIT{
	int tre[200010];
	void clear(){
		for(int i=1;i<=n;++i) tre[i]=0;
	}
	int query(int x){
		int res=0;
		while(x){
			(res+=tre[x])%=mod;
			x-=x&-x;
		}
		return res;
	}
	void update(int x,int k){
		while(x<=n){
			(tre[x]+=k)%=mod;
			x+=x&-x;
		}
	}
}T1,T3;
struct BIT2{
	int tre[200010];
	void clear(){
		for(int i=1;i<=n;++i) tre[i]=0;
	}
	int query(int x){
		int res=0;
		while(x<=n){
			(res+=tre[x])%=mod;
			x+=x&-x;
		}
		return res;
	}
	void update(int x,int k){
		while(x){
			(tre[x]+=k)%=mod;
			x-=x&-x;
		}
	}
}T2;

PII b[200010];
int pos[200010];
bool fl[200010];
int main(){
	T=read();
	while(T--){
		int ans=0;
		n=read();
		for(int i=1;i<=n;++i) a[i]=read(),b[i]=mp(a[i],-i);
		sort(b+1,b+n+1);
		for(int i=1;i<=n;++i) a[-b[i].se]=i,pos[i]=-b[i].se,fx[i]=sf[i]=pr[i]=0;
		// for(int i=1;i<=n;++i) printf("%d ",a[i]);
		T1.clear();
		for(int i=1;i<=n;++i){
			pr[pos[i]]=T1.query(pos[i])+1;
			T1.update(pos[i],pr[pos[i]]);
		}
		T2.clear();T3.clear();
		for(int i=n;i>=1;--i){
			sf[pos[i]]=T2.query(pos[i])+1;
			T2.update(pos[i],sf[pos[i]]);
		}
		int mx=0;
		for(int i=n;i>=1;--i){
			if(a[i]>mx){
				fl[a[i]]=1;mx=a[i];
			}
			else fl[a[i]]=0;
		}
		int ls=n;
		// fx[pos[n]]=1;T3.update(pos[n],1);
		for(int i=n;i>=1;--i){
			if(fl[i]){
				fx[pos[i]]=1;
				for(int j=i+1;j<=ls;++j){
					T3.update(pos[j],mod-fx[pos[j]]);
				}
				T3.update(pos[i],fx[pos[i]]);ls=i;
			}
			else{
				fx[pos[i]]=(T3.query(pos[ls])-T3.query(pos[i])+mod)%mod;
				T3.update(pos[i],fx[pos[i]]);
			}
		}
		for(int i=1;i<=n;++i) (ans+=1ll*(sf[i]+mod-fx[i])*pr[i]%mod)%=mod;
		printf("%d\n",ans);
	}
}