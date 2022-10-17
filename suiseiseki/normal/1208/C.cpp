#include <cstdio>
#define Maxn 1000
int n;
int a[Maxn+5][Maxn+5];
int main(){
	scanf("%d",&n);
	int tot=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			a[i][j]=tot;
			tot++;
		}
	}
	tot=1;
	for(int k=0;k<(n>>2);k++){
		for(int l=0;l<(n>>2);l++){
			if(k==0&&l==0){
				continue;
			}
			for(int i=1;i<=4;i++){
				for(int j=1;j<=4;j++){
					a[i+(k<<2)][j+(l<<2)]=a[i][j]+tot*16;
				}
			}
			tot++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		puts("");
	}
	return 0;
}