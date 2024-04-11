#include <cstdio>
#define Maxn 100000
int a[Maxn+5];
int b[Maxn+5];
int c[Maxn+5];
int n;
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		b[i]=c[b[i]];
	}
	int ans=0;
	int minn=n+1;
	for(int i=n;i>0;i--){
		if(b[i]>minn){
			ans++;
		}
		minn=mn(minn,b[i]);
	}
	printf("%d\n",ans);
	return 0;
}