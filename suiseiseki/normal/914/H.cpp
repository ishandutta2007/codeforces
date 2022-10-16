#include <cstdio>
const int Maxn=200;
int n,d,Mod;
int f[Maxn+5][Maxn+5];
int sum[Maxn+5];
int C[Maxn+5][Maxn+5];
int main(){
	scanf("%d%d%d",&n,&d,&Mod);
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(0ll+C[i-1][j]+C[i-1][j-1])%Mod;
		}
	}
	f[1][0]=1;
	sum[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=d;j++){
			for(int k=1;k<=i;k++){
				f[i][j]=(f[i][j]+1ll*f[i-k][j-1]*sum[k]%Mod*C[i-2][k-1])%Mod;
			}
		}
		for(int j=0;j<d;j++){
			sum[i]=(0ll+sum[i]+f[i][j])%Mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=d;j++){
			for(int k=0;j+k<=d;k++){
				ans=(ans+1ll*f[i][j]*f[n-i+1][k])%Mod;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<d;j++){
			for(int k=0;k<d;k++){
				ans=(ans-1ll*f[i][j]*f[n-i][k]%Mod+Mod)%Mod;
			}
		}
	}
	ans=2ll*ans*n%Mod*(n-1)%Mod;
	printf("%d\n",ans);
	return 0;
}