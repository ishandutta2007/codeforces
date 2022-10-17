#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	if(n<=2){
		puts("NO");
	}
	else if(n&1){
		puts("NO");
	}
	else{
		puts("YES");
	}
	return 0;
}