#include<stdio.h>

#define N 17000000
int x[30], y[30], a, b, c[30], p[N], q[N], tmp, dp[N], n, tot, cnt;

inline int sqr(int x){ return x * x; }

int main(){
	//freopen("c.in", "r", stdin);
	scanf("%d %d", &a, &b);
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%d %d", &x[i], &y[i]);
		x[i] -= a;
		y[i] -= b;
	}
	tot = (1 << n) - 1;
	for(int bit = 1; bit <= tot; bit ++){
		cnt = 0;
		for(int j = 0; j < n; j ++){
			if( (bit|(1 << j)) == bit){ c[cnt ++] = j; }
		}
		if(cnt == 1){ dp[bit] = 2 * ( sqr(x[c[0]]) + sqr(y[c[0]]) ); p[bit] = c[0] + 1; continue; }
		dp[bit] = 2 * (sqr(x[c[0]]) + sqr(y[c[0]]) )+ dp[bit - (1 << c[0])]; p[bit] = c[0] + 1;
		for(int j = 1; j < cnt; j ++){
			tmp = sqr(x[c[0]]) + sqr(y[c[0]]) + sqr(x[c[j]]) + sqr(y[c[j]]) + sqr(x[c[j]] - x[c[0]]) + sqr(y[c[j]] - y[c[0]]) + dp[bit - (1 << c[0]) - (1 << c[j])];
			if(tmp < dp[bit]){ dp[bit] = tmp; p[bit] = c[0] + 1; q[bit] = c[j] + 1; }
		}
	}
	printf("%d\n0", dp[tot]);
	while(tot){
		printf(" %d", p[tot]); a = 0; a += (1 << (p[tot] - 1) );
		if(q[tot]){ printf(" %d", q[tot]); a += (1 << (q[tot] - 1) ); }
		printf(" 0"); tot -= a;
	}puts("");
}