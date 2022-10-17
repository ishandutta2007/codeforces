#include <cstdio>
int main(){
	int t;
	int a,b,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&n);
		n++;
		if(n%3==0){
			printf("%d\n",a^b);
		}
		else if(n%3==1){
			printf("%d\n",a);
		}
		else{
			printf("%d\n",b);
		}
	}
	return 0;
}
/*
a b a^b a b ...
*/