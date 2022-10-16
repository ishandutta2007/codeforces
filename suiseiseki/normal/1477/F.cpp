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
const int Mod=998244353;
const int Maxn=50;
const int Maxk=2000;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int fac[Maxk+5],inv_f[Maxk+5];
void init(){
	fac[0]=1;
	for(int i=1;i<=Maxk;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
	}
	inv_f[Maxk]=find_inv(fac[Maxk]);
	for(int i=Maxk-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int n,k;
int a[Maxn+5];
int sum_len,inv_sum;
int f[Maxn+5][Maxk+5][Maxn+5];
int find_val(int a,int b){
	return 1ll*fac[a]*find_inv(quick_power(1-b,a+1,Mod))%Mod;
}
int main(){
	init();
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum_len+=a[i];
	}
	inv_sum=find_inv(sum_len);
	f[0][0][0]=1;
	int s_k=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=(a[i]-1)/k;j++){
			int p=1ll*((j&1)?-1:1)*inv_f[j]*quick_power(1ll*(a[i]-j*k)*inv_sum%Mod,j,Mod)%Mod;
			for(int l=0;l<=s_k;l++){
				for(int t=0;t<i;t++){
					if(f[i-1][l][t]==0){
						continue;
					}
					f[i][l+j][t]=(f[i][l+j][t]+1ll*f[i-1][l][t]*p)%Mod;
				}
			}
			if(j>0){
				p=1ll*((j&1)?-1:1)*inv_f[j-1]*quick_power(1ll*(a[i]-j*k)*inv_sum%Mod,j-1,Mod)%Mod;
				for(int l=0;l<=s_k;l++){
					for(int t=0;t<i;t++){
						if(f[i-1][l][t]==0){
							continue;
						}
						f[i][l+j][t+1]=(f[i][l+j][t+1]+1ll*f[i-1][l][t]*p)%Mod;
					}
				}
			}
		}
		s_k+=(a[i]-1)/k;
	}
	for(int i=0;i<=s_k;i++){
		for(int j=0;j<=n;j++){
			f[n][i][j]=-f[n][i][j];
		}
	}
	int ans=0;
	for(int i=0;i<=s_k;i++){
		for(int j=0;j<=n&&j<=i;j++){
			ans=(ans+1ll*f[n][i][j]*find_val(i-j,1ll*(sum_len-i*k)*inv_sum%Mod))%Mod;
		}
	}
	ans=(ans%Mod+Mod)%Mod;
	printf("%d\n",ans);
	return 0;
}