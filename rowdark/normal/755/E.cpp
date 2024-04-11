#include<stdio.h>
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	if(m>3||m<2||n<4||(n==4&&m==2)){
		printf("-1\n");
	}
	else{
		if(m==2){
			printf("%d\n",n);
			for(int i=1;i<=n;++i) printf("%d %d\n",i,i==n?1:i+1);
		}
		else{
			printf("%d\n",3+(n-4)*2);
			printf("1 2\n");
			printf("2 3\n");
			printf("3 4\n");
			for(int i=5;i<=n;++i) printf("2 %d\n3 %d\n",i,i);
		}
	}
	return 0;
}