#include <cstdio>
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	int t;
	int a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		if(gcd(a,b)==1){
			puts("Finite");
		}
		else{
			puts("Infinite");
		}
	}
	return 0;
}