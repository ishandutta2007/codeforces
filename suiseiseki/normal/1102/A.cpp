#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	if((n&3)==0){
		puts("0");
	}
	else if((n&3)==1){
		puts("1");
	}
	else if((n&3)==2){
		puts("1");
	}
	else if((n&3)==3){
		puts("0");
	}
	return 0;
}