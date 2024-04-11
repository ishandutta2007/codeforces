#include <cstdio>
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int ans=0;
		for(int i=0;i<=a&&(i<<1)<=b;i++){
			ans=mx(ans,i+(i<<1)+mn(b-(i<<1),(c>>1))*3);
		}
		printf("%d\n",ans);
	}
	return 0;
}