#include <cstdio>
#define Maxn 100
int a[Maxn+5];
int ab(int a){
	return a<0?-a:a;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int now;
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<k;i++){
		now=0;
		for(int j=1;j<=n;j++){
			if(j%k==i){
				continue;
			}
			now+=a[j];
		}
		ans=mx(ans,ab(now));
	}
	printf("%d\n",ans);
	return 0;
}