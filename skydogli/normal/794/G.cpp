#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 1000000007
#define MN 600005
int mu[MN],p[MN],vis[MN];
int bin[MN],f[MN],fac[MN],dfac[MN],inv[MN];
int n,cnt;
char A[MN],B[MN];
int C(int m,int n){
	if(m<n||n<0)return 0;
	return fac[m]*dfac[n]%Mod*dfac[m-n]%Mod;
}
void init(int n){
	mu[1]=1;
	for(int i=2;i<=n;++i){
		if(!vis[i]){p[++cnt]=i;mu[i]=Mod-1;}
		for(int j=1;p[j]*i<=n;++j){
			vis[p[j]*i]=1;
			if(i%p[j]==0)break;
			mu[p[j]*i]=-mu[i];
		}
	}
	bin[0]=1;for(int i=1;i<=n+1;++i)bin[i]=(bin[i-1]<<1)%Mod;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i)
			f[j]=(f[j]+bin[i]*mu[j/i])%Mod;
	for(int i=1;i<=n;++i){
		f[i]=(f[i-1]+(n/i)*(n/i)%Mod*f[i])%Mod;
	}
}
int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}
int _f(int a,int b){
	if(a==b&&!a)return f[n];
	if(a*b>=0)return 0;
	a=abs(a);b=abs(b);
	int g=gcd(a,b);
	return bin[n/max(a/g,b/g)+1]-2;
}
signed main(){
	scanf("%s%s%lld",A+1,B+1,&n);
	int l1=strlen(A+1),l2=strlen(B+1);
	int nn=max(l1,l2)*2;
	fac[0]=dfac[0]=fac[1]=dfac[1]=inv[1]=1;
	for(int i=2;i<=nn;++i){
		fac[i]=fac[i-1]*i%Mod;
		inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
		dfac[i]=dfac[i-1]*inv[i]%Mod;
	}
	init(n);
	int P=0,Q=0,aa=0,bb=0;
	for(int i=1;i<=l1;++i)P+=(A[i]=='?'),aa+=(A[i]=='A'),bb+=(A[i]=='B');
	for(int i=1;i<=l2;++i)Q+=(B[i]=='?'),aa-=(B[i]=='A'),bb-=(B[i]=='B');
	int ans=0;
	for(int k=-max(P,Q);k<=max(P,Q);++k){
		ans=(ans+_f(aa+k,bb+P-Q-k)*C(P+Q,P-k))%Mod;
	}
	if(l1==l2){
		bool ok=1;
		for(int i=1;i<=l1;++i)
			if(A[i]!=B[i]&&A[i]!='?'&&B[i]!='?')ok=0;
		if(ok){
			int tot=1;
			for(int i=1;i<=l1;++i)
				if(A[i]==B[i]&&A[i]=='?'){
					tot=(tot<<1)%Mod;
				}
			ans=(ans-tot*f[n]%Mod+Mod)%Mod;
	//		cerr<<"? "<<ans<<endl;
			ans=(ans+(bin[n+1]-2)*(bin[n+1]-2)%Mod*tot)%Mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}