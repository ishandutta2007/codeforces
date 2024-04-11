#include <cstdio>
const int Maxn=10000;
int n;
int a[Maxn+5];
struct Answer{
	int i,j,x;
}ans[Maxn*3+5];
int len;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum%n!=0){
			puts("-1");
			continue;
		}
		sum/=n;
		len=0;
		for(int i=2;i<=n;i++){
			if(a[i]%i!=0){
				ans[++len].i=1;
				ans[len].j=i;
				ans[len].x=i-a[i]%i;
				a[i]+=ans[len].x;
				a[1]-=ans[len].x;
			}
			ans[++len].i=i;
			ans[len].j=1;
			ans[len].x=a[i]/i;
			a[i]=0;
			a[1]+=ans[len].x*i;
		}
		for(int i=2;i<=n;i++){
			ans[++len].i=1;
			ans[len].j=i;
			ans[len].x=sum;
		}
		printf("%d\n",len);
		for(int i=1;i<=len;i++){
			printf("%d %d %d\n",ans[i].i,ans[i].j,ans[i].x);
		}
	}
	return 0;
}