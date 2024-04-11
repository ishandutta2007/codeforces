#include <cstdio>
int main(){
	int k;
	scanf("%d",&k);
	int sum;
	for(int n=1;n<=2000;n++){
		for(int m=1;m<=n;m++){
			if(k%m!=0){
				continue;
			}
			if(k/m+n>(n-m)*1000000-m){
				continue;
			}
			printf("%d\n",n);
			sum=k/m+n;
			for(int i=1;i<=m;i++){
				printf("%d ",-1);
			}
			for(int i=m+1;i<=n;i++){
				if(sum>=1000000){
					printf("%d ",1000000);
					sum-=1000000;
				}
				else{
					printf("%d ",sum);
					sum=0;
				}
			}
			puts("");
			return 0;
		}
	}
	puts("-1");
	return 0;
}
///