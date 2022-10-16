#include <cstdio>
#define Maxn 300000
int n,q;
int a[Maxn+5];
int g[Maxn+5][20];
int f[Maxn+5][20];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<20;j++){
			if((1<<j)&a[i]){
				g[i+1][j]=i;
			}
			else{
				g[i+1][j]=g[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<20;j++){
			if((1<<j)&a[i]){
				f[i][j]=i;
			}
			else{
				for(int k=0;k<20;k++){
					if((1<<k)&a[i]){
						int u=g[i][k];
						if((1<<j)&a[u]){
							f[i][j]=mx(f[i][j],u);
						}
						else{
							f[i][j]=mx(f[i][j],f[u][j]);
						}
					}
				}
			}
		}
	}
	int x,y;
	bool flag;
	while(q--){
		scanf("%d%d",&x,&y);
		flag=0;
		for(int i=0;i<20;i++){
			if((1<<i)&a[x]){
				if(f[y][i]>=x){
					flag=1;
					break;
				}
			}
		}
		if(flag){
			puts("Shi");
		}
		else{
			puts("Fou");
		}
	}
	return 0;
}