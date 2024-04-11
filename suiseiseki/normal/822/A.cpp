#include <cstdio>
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int x=mn(a,b);
	int ans=1;
	for(int i=2;i<=x;i++){
		ans*=i;
	}
	printf("%d\n",ans);
	return 0;
}