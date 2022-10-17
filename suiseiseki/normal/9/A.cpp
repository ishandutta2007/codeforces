#include <cstdio>
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=7-(n>m?n:m);
	int x=gcd(ans,6);
	printf("%d/%d",ans/x,6/x);
	return 0;
}