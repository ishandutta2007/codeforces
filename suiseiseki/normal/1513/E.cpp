#include <cstdio>
#include <algorithm>
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
typedef long long ll;
const int Maxn=100000;
const int Mod=1000000007;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int n;
int a[Maxn+5];
int fac[Maxn+5],inv_f[Maxn+5];
void init(){
	fac[0]=1;
	for(int i=1;i<=Maxn;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
	}
	inv_f[Maxn]=find_inv(fac[Maxn]);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	return 1ll*fac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int main(){
	init();
	scanf("%d",&n);
	ll sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum%n!=0){
		puts("0");
		return 0;
	}
	sum/=n;
	int num_0=0,num_1=0,num_2=0;
	for(int i=1;i<=n;i++){
		if(a[i]<sum){
			num_0++;
		}
		else if(a[i]==sum){
			num_1++;
		}
		else{
			num_2++;
		}
	}
	int val=1;
	std::sort(a+1,a+1+n);
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<=n&&a[j]==a[i]){
			j++;
		}
		j--;
		val=1ll*val*inv_f[j-i+1]%Mod;
	}
	if(num_0==1||num_2==1){
		int ans=1ll*fac[n]*val%Mod;
		printf("%d\n",ans);
	}
	else{
		if(num_0>0&&num_2>0){
			int ans=2ll*fac[num_1]*C(n,num_1)%Mod*fac[num_0]%Mod*fac[num_2]%Mod*val%Mod;
			printf("%d\n",ans);
		}
		else{
			int ans=1ll*fac[n]*val%Mod;
			printf("%d\n",ans);
		}
	}
	return 0;
}