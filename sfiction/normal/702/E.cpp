#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, PII> PLP;

const int MAXN = 1E5 + 10;

PLP dp[2][MAXN], ans[MAXN];

PLP merge(const PLP &a, const PLP &b){
	return PLP(a.st + b.st, PII(min(a.nd.st, b.nd.st), b.nd.nd));
}

int main(){
	int n;
	ll K;
	scanf("%d%I64d", &n, &K);
	for (int i = 0; i < n; ++i){
		scanf("%d", &dp[0][i].nd.nd);
		ans[i].nd.nd = i;
	}
	for (int i = 0; i < n; ++i){
		scanf("%d", &dp[0][i].nd.st);
		dp[0][i].st = dp[0][i].nd.st;
		ans[i].nd.st = 1 << 30;
	}

	PLP *f = dp[0], *g = dp[1];
	for (; K; K >>= 1, swap(f, g)){
		if (K & 1){
			for (int i = 0; i < n; ++i)
				ans[i] = merge(ans[i], f[ans[i].nd.nd]);
		}
		for (int i = 0; i < n; ++i)
			g[i] = merge(f[i], f[f[i].nd.nd]);
	}
	for (int i = 0; i < n; ++i)
		printf("%I64d %d\n", ans[i].st, ans[i].nd.st);
	return 0;
}