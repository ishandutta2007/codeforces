#include<cstdio>
using namespace std;

int main(){
	int n;scanf("%d",&n);
	if(n<4){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if(n%4==0){
		printf("1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n");
		for(int i=5;i<n;i+=4){
			printf("24 + %d = %d\n",i,24+i);
			printf("%d + %d = %d\n",24+i,i+3,27+i*2);
			printf("%d - %d = %d\n",27+i*2,i+1,26+i);
			printf("%d - %d = 24\n",26+i,i+2);
		}
	}
	if(n%4==1){
		printf("4 * 5 = 20\n3 - 1 = 2\n2 * 2 = 4\n4 + 20 = 24\n");
		for(int i=6;i<n;i+=4){
			printf("24 + %d = %d\n",i,24+i);
			printf("%d + %d = %d\n",24+i,i+3,27+i*2);
			printf("%d - %d = %d\n",27+i*2,i+1,26+i);
			printf("%d - %d = 24\n",26+i,i+2);
		}
	}
	if(n%4==2){
		printf("4 * 6 = 24\n5 + 1 = 6\n2 * 3 = 6\n6 - 6 = 0\n24 + 0 = 24\n");
		for(int i=7;i<n;i+=4){
			printf("24 + %d = %d\n",i,24+i);
			printf("%d + %d = %d\n",24+i,i+3,27+i*2);
			printf("%d - %d = %d\n",27+i*2,i+1,26+i);
			printf("%d - %d = 24\n",26+i,i+2);
		}
	}
	if(n%4==3){
		printf("4 * 6 = 24\n5 * 1 = 5\n2 * 5 = 10\n3 + 7 = 10\n10 - 10 = 0\n24 + 0 = 24\n");
		for(int i=8;i<n;i+=4){
			printf("24 + %d = %d\n",i,24+i);
			printf("%d + %d = %d\n",24+i,i+3,27+i*2);
			printf("%d - %d = %d\n",27+i*2,i+1,26+i);
			printf("%d - %d = 24\n",26+i,i+2);
		}
	}
	return 0;
}