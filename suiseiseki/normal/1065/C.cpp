#include <cstdio>
int a[200005];
int sum[200005];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[1]++;
		sum[a[i]+1]--;
	}
	bool get_ans=1;
	for(int i=2;i<=n&&get_ans;i++){
		if(a[i]!=a[i-1]){
			get_ans=0;
		}
	}
	if(get_ans){
		puts("0");
		return 0;
	}
	for(int i=1;i<=200000;i++){
		sum[i]+=sum[i-1];
	}
	int i=200000;
	int now_sum;
	int ans=0;
	while(i>0){
		now_sum=0;
		while(i>0&&now_sum+sum[i]<=k){
			now_sum+=sum[i];
			i--;
		}
		ans++;
		if(i<1||sum[i]>=n){
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}