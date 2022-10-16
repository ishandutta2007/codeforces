#include <cstdio>
#define Maxn 1000000
#define Mod 1000000007
int n,m,a,b;
int ksm(int a,int b){
	int ans=1;
	if(b<0){
		b+=Mod-1;
	}
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
int frac[Maxn+5],inv[Maxn+5];
void init(){
	frac[0]=1;
	for(int i=1;i<=Maxn;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv[Maxn]=ksm(frac[Maxn],Mod-2);
	for(int i=Maxn-1;i>0;i--){
		inv[i]=1ll*inv[i+1]*(i+1)%Mod;
	}
	inv[0]=1;
}
int C(int n,int m){
	return 1ll*frac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int A(int n,int m){
	return 1ll*frac[n]*inv[n-m]%Mod;
}
int main(){
	init();
	scanf("%d%d%d%d",&n,&m,&a,&b);
	int ans=0;
	for(int i=1;i<=m&&i<n;i++){
		ans+=1ll*A(n-2,i-1)*C(m-1,i-1)%Mod*(i+1)%Mod*ksm(n,n-(i+1)-1)%Mod*ksm(m,n-1-i)%Mod;
		ans%=Mod;
	}
	printf("%d\n",ans);
	return 0;
}