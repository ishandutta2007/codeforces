#include <cstdio>
template<typename Elem>
int quick_power(int a,Elem b,int Mod){
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
const int Mod=998244353;
int n;
ll sum_0[Maxn+5];
int sum_1[Maxn+5],sum_2[Maxn+5],sum_3[Maxn+5];
int f[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,a;
		scanf("%d%d",&x,&a);
		int s_1=1ll*x*a%Mod,s_2=1ll*x*x%Mod*a%Mod,s_3=1ll*x*x%Mod*a%Mod*(a-1)%Mod;
		for(int j=1;j*j<=x;j++){
			if(x%j==0){
				sum_3[j]=(sum_3[j]+s_3+2ll*s_1*sum_1[j])%Mod;
				sum_2[j]=(sum_2[j]+s_2)%Mod;
				sum_1[j]=(sum_1[j]+s_1)%Mod;
				sum_0[j]=(sum_0[j]+a);
				if(j*j!=x){
					sum_3[x/j]=(sum_3[x/j]+s_3+2ll*s_1*sum_1[x/j])%Mod;
					sum_2[x/j]=(sum_2[x/j]+s_2)%Mod;
					sum_1[x/j]=(sum_1[x/j]+s_1)%Mod;
					sum_0[x/j]=(sum_0[x/j]+a);
				}
			}
		}
	}
	for(int i=Maxn;i>0;i--){
		if(sum_0[i]==0){
			continue;
		}
		int p_2=0,p_3=0;
		if(sum_0[i]>2){
			p_3=quick_power(2,sum_0[i]-3,Mod);
			p_2=(p_3<<1)%Mod;
		}
		else if(sum_0[i]>1){
			p_2=quick_power(2,sum_0[i]-2,Mod);
		}
		if(sum_0[i]>1){
			f[i]=(f[i]+1ll*p_2*((sum_0[i]-1)%Mod)%Mod*sum_2[i])%Mod;
			f[i]=(f[i]+1ll*p_2*sum_3[i])%Mod;
		}
		if(sum_0[i]>2){
			f[i]=(f[i]+1ll*p_3*((sum_0[i]-2)%Mod)%Mod*sum_3[i])%Mod;
		}
		for(int j=i+i;j<=Maxn;j+=i){
			f[i]=(f[i]-f[j]+Mod)%Mod;
		}
	}
	printf("%d\n",f[1]);
	return 0;
}