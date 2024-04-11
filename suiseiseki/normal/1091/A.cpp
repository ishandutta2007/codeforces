#include <cstdio>
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	int now=mn(r,mn(g-1,b-2));
	printf("%d\n",now*3+3);
	return 0;
}