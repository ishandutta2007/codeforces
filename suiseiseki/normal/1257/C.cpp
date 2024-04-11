#include <cstdio>
#define Maxn 200000
int a[Maxn+5],b[Maxn+5];
int lst[Maxn+5];
int n;
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int t;
	scanf("%d",&t);
	int ans;
	while(t--){
		scanf("%d",&n);
		ans=n+1;
		for(int i=1;i<=n;i++){
			lst[i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=lst[a[i]];
			lst[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			if(b[i]>0){
				ans=mn(ans,i-b[i]+1);
			}
		}
		if(ans==n+1){
			ans=-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}