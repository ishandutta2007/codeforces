#include <cstdio>
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int now=(k<<1)+1;
	int ans=(n+now-1)/now;
	printf("%d\n",ans);
	int last=n-(1+now*(ans-1)+k);
	if(last<0){
		last=0;
	}
	int x=1+last;
	while(ans--){
		printf("%d ",x);
		x+=now;
	}
	puts("");
	return 0;
}