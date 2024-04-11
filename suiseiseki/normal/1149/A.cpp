#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 200000
int a[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	if(a[1]==2){
		for(int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		puts("");
	}
	else if(a[2]==2){
		printf("2 1 ");
		for(int i=3;i<=n;i++){
			printf("%d ",a[i]);
		}
		puts("");
	}
	else if(a[3]==2){
		printf("2 1 ");
		for(int i=4;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("1 ");
		puts("");
	}
	else{
		int x;
		for(x=1;x<=n&&a[x]==1;x++);
		x--;
		if(x&1){
			for(int i=1;i<=n;i++){
				printf("%d ",a[i]);
			}
			puts("");
		}
		else{
			for(int i=1;i<x;i++){
				printf("%d ",a[i]);
			}
			for(int i=x+1;i<=n;i++){
				printf("%d ",a[i]);
			}
			printf("1 ");
			puts("");
		}
	}
	return 0;
}