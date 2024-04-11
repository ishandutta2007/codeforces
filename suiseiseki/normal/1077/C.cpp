#include <cstdio>
#define Inf (1<<30)
int a[200005];
int main(){
	int n;
	scanf("%d",&n);
	int maxn_1=-Inf,maxn_2=-Inf;
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		if(a[i]>maxn_1){
			maxn_2=maxn_1;
			maxn_1=a[i];
		}
		else if(a[i]>maxn_2){
			maxn_2=a[i];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==maxn_1){
			if(sum-a[i]-maxn_2==maxn_2){
				ans++;
			}
		}
		else{
			if(sum-a[i]-maxn_1==maxn_1){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		if(a[i]==maxn_1){
			if(sum-a[i]-maxn_2==maxn_2){
				printf("%d ",i);
			}
		}
		else{
			if(sum-a[i]-maxn_1==maxn_1){
				printf("%d ",i);
			}
		}
	}
	if(ans!=0){
		puts("");
	}
	return 0;
}