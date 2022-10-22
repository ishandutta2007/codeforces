#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 100105
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
#define Mod 1000000007
int n,m;
int a[MN];
const int N=100;
int tag[N+5][MN],sum[MN];
int fac[MN],dfac[MN],inv[MN];
int C(int m,int n){
	if(m<n)return 0;
	return fac[m]*dfac[n]%Mod*dfac[m-n]%Mod;
}
signed main(){
	n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	fac[0]=dfac[0]=fac[1]=dfac[1]=inv[1]=1;
	for(int i=2;i<=n+N;++i){
		fac[i]=fac[i-1]*i%Mod;
		inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
		dfac[i]=dfac[i-1]*inv[i]%Mod;
	}
	for(int i=1;i<=m;++i){
		int l=read(),r=read(),k=read();
		tag[N-k][l]++;
		for(int j=0;j<=k;++j){
			tag[N-(k-j)][r+1]=(tag[N-(k-j)][r+1]+Mod-C(r-l+j,j))%Mod;		
		}
	}
	for(int i=0;i<=N;++i){
		for(int j=1;j<=n;++j){
			sum[j]=(sum[j]+sum[j-1]+tag[i][j])%Mod;
		}
	}
	for(int i=1;i<=n;++i)printf("%lld ",(sum[i]+a[i])%Mod);
	return 0;
}