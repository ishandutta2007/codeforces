#include <cstdio>
int main(){
	int x;
	scanf("%d",&x);
	if(x<0){
		x=-x;
	}
	int ans=0;
	for(int i=1,t=1;x;i++,t+=i){
		if(t==x||(t>x&&(!((t-x)&1)))){
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}