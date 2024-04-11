#include <cstdio>
int mn(int a,int b){
	return a<b?a:b;
}
int ab(int a){
	return a<0?-a:a;
}
int main(){
	int t;
	int n,d,x,y;
	scanf("%d",&t);
	int ans;
	while(t--){
		scanf("%d%d%d%d",&n,&x,&y,&d);
		if((ab(y-x))%d==0){
			printf("%d\n",(ab(y-x))/d);
		}
		else{
			ans=0x7fffffff;
			if((y-1)%d==0){
				ans=mn(ans,(x+d-2)/d+(y-1)/d);
			}
			if((n-y)%d==0){
				ans=mn(ans,(n-x+d-1)/d+(n-y)/d);
			}
			if(ans==0x7fffffff){
				puts("-1");
			}
			else{
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}