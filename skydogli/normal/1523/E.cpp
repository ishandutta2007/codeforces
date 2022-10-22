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
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
#define Mod 1000000007
int ksm(int a,int x){
	int ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
int T,n,k;
int fac[MN],dfac[MN],inv[MN],val[MN];
int C(int m,int n){
	if(m<n)return 0;
//	cerr<<"C: "<<m<<" "<<n<<endl;
	return fac[m]*dfac[n]%Mod*dfac[m-n]%Mod;
}
signed main(){
	T=read();
	while(T--){
		n=read();k=read();
		fac[0]=dfac[0]=fac[1]=dfac[1]=inv[1]=1;
		for(int i=2;i<=n+n;++i){
			fac[i]=fac[i-1]*i%Mod;
			inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
			dfac[i]=dfac[i-1]*inv[i]%Mod;
		}
		int ans=0,tot=0,N=0;
		for(int i=1;(i-1)*k+1<=n;++i){
//			int tmp=C(i-1+n-k*(i-1)+k-1,n-k*(i-1)+k-1)*fac[i-1]%Mod*((i-1)*(k-1))%Mod;
			val[i]=C(i+n-k*(i-1)-1,n-k*(i-1)-1)*fac[i]%Mod;
			N=i;
		}
		val[N+1]=0;
		for(int i=N;i;--i){
	//		cerr<<i<<": "<<val[i]<<" "<<val[i]*(n-i)-val[i+1]<<endl;
			ans=(ans+(val[i]*(n-i)-val[i+1]+Mod)%Mod*fac[n-i-1]%Mod*dfac[n]%Mod*(i+1))%Mod;
		}
		printf("%lld\n",ans%Mod);
	}
	return 0;
}