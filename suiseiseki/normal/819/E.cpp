#include <cstdio>
const int Maxn=300;

int main(){
	int n;
	scanf("%d",&n);
	if(n&1){
		int ans=0;
		for(int i=2;i<=n;i+=2){
			ans+=2;
			for(int j=i+2;j<=n;j+=2){
				ans+=2;
			}
		}
		printf("%d\n",ans);
		for(int i=2;i<=n;i+=2){
			printf("3 1 %d %d\n",i,i+1);
			printf("3 1 %d %d\n",i,i+1);
			for(int j=i+2;j<=n;j+=2){
				printf("4 %d %d %d %d\n",i,j,i+1,j+1);
				printf("4 %d %d %d %d\n",i,j,i+1,j+1);
			}
		}
	}
	else{
		int ans=3;
		for(int i=5;i<=n;i+=2){
			ans+=3;
			for(int j=3;j<i;j+=2){
				ans+=2;
			}
		}
		printf("%d\n",ans);
		puts("4 1 3 2 4");
		puts("4 1 3 4 2");
		puts("4 1 2 3 4");
		for(int i=5;i<=n;i+=2){
			printf("3 1 %d %d\n",i,i+1);
			printf("3 2 %d %d\n",i,i+1);
			printf("4 1 %d 2 %d\n",i,i+1);
			for(int j=3;j<i;j+=2){
				printf("4 %d %d %d %d\n",i,j,i+1,j+1);
				printf("4 %d %d %d %d\n",i,j,i+1,j+1);
			}
		}
	}
	return 0;
}