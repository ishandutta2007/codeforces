#include <cstdio>
#include <cstring>
const int Maxn=400;
const int Mod=998244353;
int c[26];
int n;
int f[2][205][205][3][3];
int g[Maxn+5][Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=0;i<26;i++){
		scanf("%d",&c[i]);
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			f[0][(i==1)+(j==1)][(i==2)+(j==2)][i][j]=(i?1:24)*(j?1:24);
		}
	}
	for(int i=3;i<=n;i++){
		int cur=i&1;
		memset(f[cur],0,sizeof f[cur]);
		for(int u=0;u<=(n>>1)+1;u++){
			for(int v=0;v<=(n>>1)+2;v++){
				for(int x=0;x<3;x++){
					for(int y=0;y<3;y++){
						for(int z=0;z<3;z++){
							if(x==z&&x){
								continue;
							}
							if(x==z){
								f[cur][u][v][y][z]=(f[cur][u][v][y][z]+23ll*f[cur^1][u][v][x][y])%Mod;
							}
							else{
								f[cur][u+(z==1)][v+(z==2)][y][z]=(f[cur][u+(z==1)][v+(z==2)][y][z]+1ll*f[cur^1][u][v][x][y]*(z?1:24))%Mod;
							}
						}
					}
				}
			}
		}
	}
	for(int i=(n>>1)+1;i>=0;i--){
		for(int j=(n>>1)+1;j>=0;j--){
			g[i][j]=(0ll+g[i+1][j]+g[i][j+1]-g[i+1][j+1]+Mod)%Mod;
			for(int x=0;x<3;x++){
				for(int y=0;y<3;y++){
					g[i][j]=(g[i][j]+f[n&1][i][j][x][y])%Mod;
				}
			}
		}
	}
	int ans=g[0][0];
	for(int i=0;i<26;i++){
		ans=(ans-g[c[i]+1][0]+Mod)%Mod;
	}
	for(int i=0;i<26;i++){
		for(int j=i+1;j<26;j++){
			ans=(ans+g[c[i]+1][c[j]+1])%Mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}