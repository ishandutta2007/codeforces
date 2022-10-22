#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 998244353
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
int ksm(int a,int x){
	int ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
#define MN 1000005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int n;
int pw[MN],fac[MN],dfac[MN],inv[MN];
int C(int m,int n){
	if(m<n)return 0;
	return fac[m]*dfac[n]%Mod*dfac[m-n]%Mod;
}
signed main(){
	n=read();
	int tmp=ksm(3,n);
//	cerr<<"tmp: "<<tmp<<endl;
	pw[0]=1;for(int i=1;i<=n;++i)pw[i]=pw[i-1]*tmp%Mod;
	fac[0]=dfac[0]=fac[1]=dfac[1]=inv[1]=1;
	for(int i=2;i<=n;++i){
		fac[i]=fac[i-1]*i%Mod;
		inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
		dfac[i]=dfac[i-1]*inv[i]%Mod;
	}
	int ans=0,w=tmp-3,buf=1;
	for(int i=1;i<=n;++i){
		ans=(ans+buf*pw[n-i]*3)%Mod;	
//		cerr<<i<<": "<<pw[n-i]<<" "<<buf<<endl;
		buf=buf*w%Mod;
	}
//	cerr<<"tmp: "<<ans<<endl;
	int iv=ksm(w,Mod-2);
	for(int i=1;i<=n;++i){
		buf=buf*iv%Mod;
		int tmp=3*C(n,i)%Mod*ksm(ksm(3,n-i)-1,n)%Mod;
//		cerr<<"tmp: "<<tmp<<endl;
		tmp=(tmp+(ksm(3,i)-3)*C(n,i)%Mod*ksm(ksm(3,n-i),n))%Mod;
		tmp=tmp%Mod;
//		cerr<<i<<": "<<tmp<<endl;
		if(i-1&1) tmp=Mod-tmp;
		ans=(ans+tmp)%Mod;
	}
	printf("%lld\n",ans);
	return 0;
}