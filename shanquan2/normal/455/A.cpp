#include<cstdio>
using namespace std;

long long cnt[100001]={0},dp[100001]={0};
int main(){
	int n;scanf("%d",&n);
	int max=0;
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		if(x>max)max=x;
		cnt[x]++;
	}
	dp[1]=cnt[1];
	for(int i=2;i<=max;i++)
		if(dp[i-1]>dp[i-2]+i*cnt[i])dp[i]=dp[i-1];else dp[i]=dp[i-2]+i*cnt[i];
	printf("%I64d\n",dp[max]);
	return 0;
}