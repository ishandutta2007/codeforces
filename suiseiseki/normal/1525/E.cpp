#include <cstdio>
const int Maxn=20;
const int Maxm=50000;
const int Mod=998244353;
int inv[Maxn+5];
int d[Maxn+5][Maxm+5];
int n,m;
int f[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&d[i][j]);
		}
	}
	inv[1]=1;
	int all_inv=1;
	for(int i=2;i<=n;i++){
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
		all_inv=1ll*all_inv*inv[i]%Mod;
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n+1;j++){
			f[j]=0;
		}
		for(int j=1;j<=n;j++){
			f[n+2-d[j][i]]++;
		}
		int sum=1,num=0;
		for(int j=1;j<=n;j++){
			num+=f[j];
			sum=1ll*sum*num%Mod;
			num--;
		}
		ans=(ans+1ll*sum*all_inv)%Mod;
	}
	ans=(m-ans+Mod)%Mod;
	printf("%d\n",ans);
	return 0;
}