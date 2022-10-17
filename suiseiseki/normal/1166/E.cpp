#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 10000
#define Maxm 50
int a[Maxm+5][Maxn+5];
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i][0]);
		for(int j=1;j<=a[i][0];j++){
			scanf("%d",&a[i][j]);
		}
		sort(a[i]+1,a[i]+1+a[i][0]);
	}
	bool find;
	int x,y;
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			find=0;
			x=1,y=1;
			while(x<=a[i][0]&&y<=a[j][0]&&a[i][x]!=a[j][y]){
				if(a[i][x]<a[j][y]){
					x++;
				}
				else{
					y++;
				}
			}
			if(x<=a[i][0]&&y<=a[j][0]){
				find=1;
			}
			if(!find){
				puts("impossible");
				return 0;
			}
		}
	}
	puts("possible");
	return 0;
}