#include <cstdio>
#define Maxn 50000
int a[Maxn+5];
int minn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	int ans=0;
	int mn=(1<<30);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<mn){
			mn=a[i];
		}
		sum+=a[i];
	}
	ans=sum;
	int now;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			if(a[i]%j!=0){
				continue;
			}
			now=sum-mn-a[i];
			ans=minn(ans,now+mn*j+a[i]/j);
		}
	}
	printf("%d\n",ans);
	return 0;
}