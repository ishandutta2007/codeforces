#include<stdio.h>

int a[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[1001001];
long long ans;
int x, y;

int main(){
	for(int i = 1; i <= 1000000; ++i) dp[i] = dp[i / 10] + a[i % 10];
	scanf("%d%d", &x, &y);
	for(int i = x; i <= y; ++i) ans += dp[i];
	printf("%I64d\n", ans);
	return 0;
}