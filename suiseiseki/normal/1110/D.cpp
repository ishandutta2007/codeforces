#include <cstdio>
#include <cstring>
#define Maxn 1000000
int a[Maxn+5];
int f[Maxn+5][5][3];
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	memset(f,-0x3f,sizeof f);
	f[0][0][0]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=4;j++){
			for(int k=0;k<=2;k++){
				if(f[i-1][j][k]<0){
					continue;
				}
				for(int l=0;l<=j&&l<=k&&l<=a[i];l++){
					int x=a[i]-l;
					int y=x%3;
					f[i][y][mn(j-l,2)]=mx(f[i][y][mn(j-l,2)],f[i-1][j][k]+l+(x-y)/3);
					if(x>=y+3){
						f[i][mn(y+3,4)][mn(j-l,2)]=mx(f[i][mn(y+3,4)][mn(j-l,2)],f[i-1][j][k]+l+(x-y)/3-1);
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=4;i++){
		for(int j=0;j<=2;j++){
			ans=mx(ans,f[m][i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}