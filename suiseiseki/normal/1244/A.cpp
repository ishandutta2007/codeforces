#include <cstdio>
int main(){
	int t;
	int a,b,c,d,k;
	scanf("%d",&t);
	int ans_1,ans_2;
	while(t--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		ans_1=(a+c-1)/c;
		ans_2=(b+d-1)/d;
		if(ans_1+ans_2>k){
			puts("-1");
		}
		else{
			printf("%d %d\n",ans_1,ans_2);
		}
	}
	return 0;
}