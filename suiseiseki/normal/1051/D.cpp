#include <cstdio>
#define Maxn 2000
#define Maxk 2000
#define Mod 998244353
int f[Maxn+5][Maxk+5][4];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	f[1][2][0]=f[1][1][1]=f[1][1][2]=f[1][2][3]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=k;j++){
			f[i][j][0]=(((f[i-1][j][0]+f[i-1][j-1][1])%Mod+f[i-1][j-1][2])%Mod+f[i-1][j-2][3])%Mod;
			f[i][j][1]=(((f[i-1][j][0]+f[i-1][j][1])%Mod+f[i-1][j-1][2])%Mod+f[i-1][j][3])%Mod;
			f[i][j][2]=(((f[i-1][j][0]+f[i-1][j-1][1])%Mod+f[i-1][j][2])%Mod+f[i-1][j][3])%Mod;
			f[i][j][3]=(((f[i-1][j-2][0]+f[i-1][j-1][1])%Mod+f[i-1][j-1][2])%Mod+f[i-1][j][3])%Mod;
		}
	}
	printf("%d\n",(((f[n][k][0]+f[n][k][1])%Mod+f[n][k][2])%Mod+f[n][k][3])%Mod);
	return 0;
}