#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Maxn 100
int x[Maxn+5][Maxn+5];
int a[Maxn+5];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(x,0,sizeof x);
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(x[j][0]==0||a[i]-x[j][x[j][0]]!=1){
					x[j][++x[j][0]]=a[i];
					break;
				}
			}
		}
		for(int i=1;i<=n+1;i++){
			if(x[i][0]==0){
				printf("%d\n",i-1);
				break;
			}
		}
	}
	return 0;
}