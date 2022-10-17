#include <cstdio>
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=k-1;i>=0;i--){
		if(n%i==0){
			printf("%d\n",(n/i)*k+i);
			break;
		}
	}
	return 0;
}