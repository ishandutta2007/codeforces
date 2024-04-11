#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 100
struct Brick{
	int h,id;
}a[Maxn+5],b[Maxn+5];
int c[Maxn+5][Maxn+5];
int x[Maxn+5][Maxn+5];
int main(){
	int n,m,h;
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i].h);
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i].h);
		b[i].id=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&c[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(c[j][i]){
				if(b[j].h>=a[i].h){
					x[j][i]=a[i].h;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]){
				if(a[j].h>=b[i].h){
					x[i][j]=b[i].h;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]){
				if(x[i][j]==0){
					x[i][j]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",x[i][j]);
		}
		puts("");
	}
	return 0;
}