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
int n;
int fac[250010];
vector<int>vec[250010];
int son[250010];
void dfs(int x,int fa){
	for(int v:vec[x]){
		if(v!=fa){
			++son[x];dfs(v,x);
		}
	}
}

const int mod=998244353;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
inline int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
inline int sub(int x,int y){
	return x<y?x+mod-y:x-y;
}
typedef vector<int>poly;
namespace POLY{
	int p3[1<<20|1],ip3[1<<20|1];
	int x,len,R[1<<20|1];
	void init(int sz){
		x=1,len=0;
		while(x<=sz) x<<=1,++len;
		for(int i=0;i<x;++i) R[i]=(R[i>>1]>>1)|((i&1)<<len-1);
	}
	void NTT(poly &s,int f){
		for(int i=0;i<x;++i) if(R[i]>i) swap(s[i],s[R[i]]);
		for(int l=1;l<x;l<<=1){
			int w;if(f==1) w=p3[l];
			else w=ip3[l];
			for(int j=0;j<x;j+=(l<<1)){
				int sum=1;
				for(int k=0;k<l;++k){
					int a1=s[j+k],a2=1ll*sum*s[j+k+l]%mod;
					s[j+k]=add(a1,a2);s[j+k+l]=sub(a1,a2);sum=1ll*sum*w%mod;
				}
			}
		}
		if(f==-1){
			int t=qpow(x);
			for(int i=0;i<x;++i) s[i]=1ll*s[i]*t%mod;
		}
	}
	poly operator *(poly A,poly B){
		int n=A.size(),m=B.size();
		if(n<=8||m<=8||(n+m<=100)){
			poly res(n+m-1,0);
			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j){
					(res[i+j]+=1ll*A[i]*B[j]%mod)%=mod;
				}
			}
			return res;
		}
		init(n+m-1);
		A.resize(x);B.resize(x);NTT(A,1);NTT(B,1);
		for(int i=0;i<x;++i) A[i]=1ll*A[i]*B[i]%mod;
		NTT(A,-1);
		A.resize(n+m-1);
		return A;
	}
	void pre(){
		for(int i=0;i<=20;++i) p3[1<<i]=qpow(3,(mod-1)/(1<<i+1));
		for(int i=0;i<=20;++i) ip3[1<<i]=qpow(qpow(3),(mod-1)/(1<<i+1));
	}
}
using namespace POLY;
poly solve(int l,int r){
	if(l==r) return poly{1,son[l]};
	int mid=l+r>>1;
	return solve(l,mid)*solve(mid+1,r);
}
int main(){
	n=read();
	pre();
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<n;++i){
		int u=read(),v=read();vec[u].pb(v),vec[v].pb(u);
	}
	dfs(1,0);
	poly F=solve(1,n);
	int ans=0;
	for(int i=0;i<=n&&i<F.size();++i) (ans+=1ll*fac[n-i]*F[i]%mod*((i&1)?mod-1:1)%mod)%=mod;
	printf("%d\n",ans);
}