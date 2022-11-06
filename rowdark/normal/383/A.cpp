#include<stdio.h>
long long ans;
int n;
int cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		if(x==1) ++cnt;
		else ans+=cnt;
	}
	printf("%I64d\n",ans);
	scanf("%d",&n);
	return 0;
}