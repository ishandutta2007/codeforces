#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn=500000,Mod=998244353;
int f[Maxn+5],sum[Maxn+5],a[Maxn+5],n,S;
int up(int &x,int y){
	x+=y;
	if(x>=Mod){
		x-=Mod;
	}
	return x;
}
int quick_power(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		S+=a[i];
	}
	f[0]=n-1;
	int inv_S=quick_power(S,Mod-2),C2=quick_power(n-1,Mod-2);
	int C1=1ll*(n-2)*quick_power(n-1,Mod-2)%Mod;
	for(int i=1;i<S;i++){
		int p1=1ll*(S-i)*inv_S%Mod*C1%Mod;
		int p2=1ll*(S-i)*inv_S%Mod*C2%Mod;
		int p3=1ll*i*inv_S%Mod;
		f[i]=quick_power(Mod+1-p1,Mod-2);
		up(f[i],f[i-1]);
		int tmp=1ll*(p2+p3)%Mod*quick_power(p2,Mod-2)%Mod;
		up(tmp,Mod-1);
		f[i]=1ll*tmp*f[i]%Mod;
		up(f[i],quick_power(Mod+1-p1,Mod-2));
	}
	for(int i=S-1;i>=0;i--){
		sum[i]=(sum[i+1]+f[i])%Mod;
	}
	int res=0;
	for(int i=1;i<=n;i++){
		up(res,sum[a[i]]);
	}
	up(res,Mod-1ll*(n-1)*sum[0]%Mod);
	res=1ll*res*quick_power(n,Mod-2)%Mod;
	printf("%d\n",res);
	return 0;
}