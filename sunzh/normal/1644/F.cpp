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
int n,k;
int ans=0;
int p[200010];
bool vis[200010];
int mu[200010];
const int mod=998244353;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int fac[200010],ifac[200010];
int xs[200010];
void prework(int x){
	fac[0]=1;
	mu[1]=1;
	for(int i=1;i<=x;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[x]=qpow(fac[x]);
	for(int i=x-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	int tot=0;
	for(int i=2;i<=x;++i){
		if(!vis[i]) p[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&i*p[j]<=x;++j){
			vis[i*p[j]]=1;
			if(i%p[j]==0){
				mu[i*p[j]]=0;break ;
			}
			mu[i*p[j]]=-mu[i];
		}
	}
	for(int i=1;i<=n;++i) xs[n/i+(n%i!=0)]+=mu[i];
	xs[1]=0;
	for(int i=1;i<=n;++i) xs[1]-=xs[i];
}
typedef vector<int>poly;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x<y?x+mod-y:x-y;}
int x,len,R[1<<20|1];
void init(int sz){
	x=1,len=0;
	while(x<=sz) x<<=1,++len;
	for(int i=0;i<x;++i) R[i]=(R[i>>1]>>1)|((i&1)<<len-1);
}
void NTT(poly &s,int f){
	for(int i=0;i<x;++i) if(R[i]>i) swap(s[i],s[R[i]]);
	for(int l=1;l<x;l<<=1){
		int w;if(f==1) w=qpow(3,(mod-1)/(l<<1));
		else w=qpow(qpow(3),(mod-1)/(l<<1));
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
int val[200010];
bool used[200010];
int get(int x){
	if(used[x]) return val[x];
	poly f(x+1,0),g(x+1,0);
	for(int i=0;i<=x;++i) f[i]=1ll*((i&1)?mod-1:1)*ifac[i]%mod,g[i]=1ll*ifac[i]*qpow(i,x)%mod;
	f=f*g;
	// printf("x:%d\n",x);
	// for(int i=0;i<f.size();++i) printf("%d ",f[i]);printf("\n");
	for(int i=0;i<=k&&i<f.size()&&i<=x;++i) (val[x]+=f[i])%=mod;used[x]=1;
	// printf("x:%d,%d\n",x,val[x]);
	return val[x];
}
int main(){
	n=read(),k=read();
	if(n==1||k==1) {
		printf("1\n");return 0;
	}
	prework(n);
	for(int i=1;i<=n;++i) if(xs[i]) (ans+=1ll*get(i)*xs[i]%mod)%=mod;
	printf("%d\n",(ans+mod)%mod);
}