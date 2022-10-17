#include <cstdio>
int a[100005];
int main(){
	int n,k;
	int sum=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum%k!=0){
		puts("No");
		return 0;
	}
	sum/=k;
	int now_sum=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		now_sum+=a[i];
		if(now_sum==sum){
			ans++;
			now_sum=0;
		}
		if(now_sum>sum){
			puts("No");
			return 0;
		}
	}
	if(ans<k){
		puts("No");
		return 0;
	}
	puts("Yes");
	now_sum=0;
	int last=0;
	for(int i=1;i<=n;i++){
		now_sum+=a[i];
		if(now_sum==sum){
			printf("%d ",i-last);
			last=i;
			now_sum=0;
		}
	}
	puts("");
	return 0;
}