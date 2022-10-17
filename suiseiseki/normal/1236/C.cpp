#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 300
int n;
int left[Maxn+5],right[Maxn+5];
int a[Maxn+5][Maxn+5],x[Maxn+5][Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=(i-1)*n+j;
		}
		left[i]=1,right[i]=n;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((i+j)&1){
				x[i][j]=a[j][left[j]++];
			}
			else{
				x[i][j]=a[j][right[j]--];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",x[i][j]);
		}
		puts("");
	}
	return 0;
}