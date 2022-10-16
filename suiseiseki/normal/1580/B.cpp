#include <cstdio>
#include <vector>
typedef long long ll;
const int Maxn=100;
int n,m,k;
int Mod;
int C[Maxn+5][Maxn+5];
int f[Maxn+5][Maxn+5][Maxn+5];
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&Mod);
	C[0][0]=1;
	for(int i=1;i<=Maxn;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
		}
	}
	for(int i=n+1;i;i--){
		f[i][0][0]=1;
		std::vector<int> v[Maxn+5];
		for(int l=0;l<=n;l++){
			for(int j=0;j<=l;j++){
				if(f[i+1][l][j]){
					v[l].push_back(j);
				}
			}
		}
		for(int l=0;l<=n;l++){
			if(!v[l].empty()){
				for(int j=0;j+l<=n;j++){
					if(!v[j].empty()){
						for(int x:v[l]){
							for(int y:v[j]){
								f[i][j+l+1][x+y+(i==m)]=(f[i][j+l+1][x+y+(i==m)]+1ll*C[j+l][j]*f[i+1][l][x]%Mod*f[i+1][j][y])%Mod;
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n",f[1][n][k]);
	return 0;
}