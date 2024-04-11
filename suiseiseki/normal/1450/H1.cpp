#include <cstdio>
int quick_power(int a,int b,int Mod){
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
const int Maxn=200000;
const int Mod=998244353;
int n,m;
char s[Maxn+5];
int frac[Maxn+5],inv_f[Maxn+5];
int pow_2[Maxn+5];
void init(){
	frac[0]=1;
	for(int i=1;i<=Maxn;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxn]=quick_power(frac[Maxn],Mod-2,Mod);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
	pow_2[0]=1;
	for(int i=1;i<=Maxn;i++){
		pow_2[i]=(pow_2[i-1]<<1)%Mod;
	}
}
int C(int n,int m){
	return 1ll*frac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	int sum_2=0,sum_0=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='?'){
			sum_2++;
		}
		else if(s[i]=='w'){
			if(i&1){
				sum_0--;
			}
			else{
				sum_0++;
			}
		}
		else{
			if(i&1){
				sum_0++;
			}
			else{
				sum_0--;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=sum_2;i++){
		int s=sum_0+i-(sum_2-i);
		if(s%4){
			continue;
		}
		s/=4;
		if(s<0){
			s=-s;
		}
		ans=(ans+1ll*s*C(sum_2,i))%Mod;
	}
	ans=1ll*ans*quick_power(pow_2[sum_2-1],Mod-2,Mod)%Mod;
	printf("%d\n",ans);
	return 0;
}