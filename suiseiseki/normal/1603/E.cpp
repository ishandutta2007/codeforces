#include <cstdio>
const int Maxn=200;
int n,Mod;
int f[Maxn+5][Maxn+5][Maxn+5];
int inv_f[Maxn+5],fac[Maxn+5],inv[Maxn+5];
int main(){
	scanf("%d%d",&n,&Mod);
	inv[1]=1;
	for(int i=2;i<=n;i++){
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
	fac[0]=inv_f[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
		inv_f[i]=1ll*inv_f[i-1]*inv[i]%Mod;
	}
	for(int i=1;i<n;i++){
		f[n+1][i][0]=inv_f[i];
	}
	int ans=2;
	for(int i=n;i>0;i--){
		for(int j=1;j<n;j++){
			for(int k=0;k+j<=i;k++){
				if(n-j<=i){
					ans=(ans+1ll*f[i+1][j][k]*inv_f[n-j]%Mod*fac[n])%Mod;
				}
			}
		}
		for(int j=n-i+1;j<n;j++){
			for(int k=n-i;j+k<=i;k++){
				f[i][j][j+k]=(f[i][j][j+k]+f[i+1][j][k])%Mod;
			}
		}
		for(int j=n-1;j>n-i;j--){
			for(int l=1;j+l<n;l++){
				for(int k=n+1-i;k<=i;k++){
					f[i][j+l][k]=(f[i][j+l][k]+1ll*f[i][j][k]*inv_f[l])%Mod;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
//