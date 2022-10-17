#include <cstdio>
#include <cstring>
#define Maxn 16
#define Maxm 10000
#define Inf 0x3f3f3f3f
int a[Maxn][Maxm];
int f[1<<Maxn][Maxn];
int d[Maxn][Maxn];
int g[Maxn][Maxn];
int n,m;
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int ab(int a){
	return a<0?-a:a;
}
void work(int start){
	memset(f,0,sizeof f);
	f[1<<start][start]=Inf;
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				for(int k=0;k<n;k++){
					if((i^(1<<j))&(1<<k)){
						f[i][j]=mx(f[i][j],mn(f[i^(1<<j)][k],d[j][k]));
					}
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	memset(d,0x3f,sizeof d);
	memset(g,0x3f,sizeof g);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				d[i][j]=mn(d[i][j],ab(a[i][k]-a[j][k]));
			}
			for(int k=1;k<m;k++){
				g[i][j]=mn(g[i][j],ab(a[i][k-1]-a[j][k]));
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		work(i);
		for(int j=0;j<n;j++){
			ans=mx(ans,mn(f[(1<<n)-1][j],g[i][j]));
		}
	}
	printf("%d\n",ans);
	return 0;
}