#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	if(n==1||n==2){
		puts("No");
	}
	else{
		puts("Yes");
		if(n&1){
			printf("1 %d\n",n);
			printf("%d ",n-1);
			for(int i=1;i<n;i++){
				printf("%d ",i);
			}
			puts("");
		}
		else{
			printf("1 %d\n",n>>1);
			printf("%d ",n-1);
			for(int i=1;i<=n;i++){
				if(i==(n>>1)){
					continue;
				}
				printf("%d ",i);
			}
			puts("");
		}
	}
	return 0;
}