#include <cstdio>
#include <cstring>
#define Maxn 100
int f[Maxn+5][Maxn+5][5][5];
int color[Maxn+5][2];
int value[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	memset(f,-0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&color[i][0],&value[i],&color[i][1]);
		f[i][i][color[i][0]][color[i][1]]=value[i];
		f[i][i][color[i][1]][color[i][0]]=value[i];
	}
	int ans=0;
	for(int i=n;i>0;i--){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=4;k++){
				for(int l=1;l<=4;l++){
					for(int u=i;u<=j+1;u++){
						f[i][j][k][l]=mx(f[i][j][k][l],mx(f[i][u][k][l],f[u+1][j][k][l]));
						for(int o=1;o<=4;o++){
							f[i][j][k][l]=mx(f[i][j][k][l],f[i][u][k][o]+f[u+1][j][o][l]);
							f[i][j][k][l]=mx(f[i][j][k][l],f[i][u][o][l]+f[u+1][j][k][o]);
						}
					}
					ans=mx(ans,f[i][j][k][l]);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}