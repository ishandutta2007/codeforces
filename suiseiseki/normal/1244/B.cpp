#include <cstdio>
#define Maxn 1000
int n;
int a[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int t;
	scanf("%d",&t);
	int ans;
	while(t--){
		scanf("%d",&n);
		ans=n;
		for(int i=1;i<=n;i++){
			scanf("%1d",&a[i]);
			if(a[i]==1){
				ans=mx(ans,mx(i,n-i+1)*2);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}