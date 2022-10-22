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
int n,m;
int a[100010];
int p[100010];
int pr[100010];
typedef vector<int>poly;
poly F,G,H;
int pw[100010];
const int mod=998244353;
inline int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
inline void addx(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}
inline int sub(int x,int y){
	return x<y?x+mod-y:x-y;
}
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}

int p3[1<<20|1],ip3[1<<20|1];
int x,len,R[1<<20|1];
void init(int sz){
	x=1,len=0;
	while(x<=sz) x<<=1,++len;
	for(int i=0;i<x;++i) R[i]=(R[i>>1]>>1)|((i&1)<<len-1);
}
void pre(){
	for(int i=0;i<=20;++i) p3[1<<i]=qpow(3,(mod-1)/(1<<i+1));
	for(int i=0;i<=20;++i) ip3[1<<i]=qpow(qpow(3),(mod-1)/(1<<i+1));
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
	if(n<=8||m<=8){
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
void solve(int l,int r){
	if(l==r){
		if(l+l<H.size()) addx(H[l+l],1ll*F[l]*G[l]%mod);
		return ;
	}
	int mid=l+r>>1;
	solve(l,mid);solve(mid+1,r);
	poly f(mid-l+1),g(r-mid);
	for(int i=l;i<=mid;++i) f[i-l]=F[i];
	for(int i=mid+1;i<=r;++i) g[i-mid-1]=G[i];
	f=f*g;
	for(int i=0;i<f.size();++i) if(l+mid+1+i<H.size()) addx(H[l+mid+1+i],f[i]);
}
int main(){
	n=read(),m=read();
	pw[0]=1;
	for(int i=1;i<=n;++i) pw[i]=add(pw[i-1],pw[i-1]);
	for(int i=0;i<n;++i) a[i]=read();
	for(int i=0;i<m;++i) p[i]=read(),pr[p[i]-1]=1;
	pre();
	for(int i=1;i<n;++i) pr[i]+=pr[i-1];
	F.assign(4*n,0);
	F[n]=1;
	for(int i=0;i<n;++i) F[i]=1,F[i+n]=pw[i==0?0:pr[i-1]];
	G.assign(4*n,0);
	for(int i=0;i<n;++i) G[i+n]=pw[m-pr[i]],G[i+n+n]=1;
	H.assign(4*n,0);
	// for(int i=0;i<4*n;++i){
	// 	for(int j=i;j<4*n&&i+j<4*n;++j) addx(H[i+j],1ll*F[i]*G[j]%mod);
	// }
	solve(0,4*n-1);
	int ans=0;
	for(int i=0;i<n;++i){
		int res=0;
		// for(int j=0;1;++j){
		// 	if(i-j+n<0||i+j+n>=n+n+n) break ;
		// 	printf("i:%d,j:%d,i-j:%d,i+j:%d,F:%d,G:%d\n",i,j,i-j,i+j,F[i-j+n],G[i+j+n]);
		// 	(res+=(1ll*F[i-j+n]*G[i+j+n]%mod-1))%=mod;
		// }
		int k=H[2*n+2*i];
		// printf("i:%d,k:%d\n",i,k);
		// printf("res:%d\n",res);
		// printf("k:%d\n",k);
		(ans+=1ll*(k-n-min(i,n-i-1)-1)*a[i]%mod)%=mod;
	}
	printf("%d\n",1ll*ans*qpow((pw[m]-1+mod)%mod)%mod);
}