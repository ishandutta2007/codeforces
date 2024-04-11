#include<bits/stdc++.h>
using namespace std;
#define N 21

double p[N], dp[(1 << N)], ans[N];
int n, k;
#define ep 1e-9

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i ++) scanf("%lf", p + i);
	dp[0] = 1;
	for(int bit = 1; bit < (1 << n); bit ++)if(__builtin_popcount(bit) <= k){
		double rp = 1;
		for(int i = 0; i < n; i ++) if( (bit&(1<<i)) ) rp -= p[i];
		for(int i = 0; i < n; i ++) if( (bit&(1<<i)) ){
			if(p[i] < ep) continue;
			dp[bit] += dp[bit^(1<<i)] * p[i] / (rp + p[i]);
			ans[i] += dp[bit^(1<<i)] * p[i] / (rp + p[i]);
		}
	}
	for(int i = 0; i < n; i ++) printf("%.11lf ", ans[i]);
}