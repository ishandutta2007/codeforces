#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1E6 + 10;
const ll MOD = 1E9 + 7;

int n, K;
ll L;
int a[MAXN];
PII lst[MAXN];

ll dp[2][MAXN];

int main(){
	scanf("%d%I64d%d", &n, &L, &K);
	K = min((ll)K, (L - 1) / n + 1);
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		lst[i] = PII(a[i], i);
	}
	sort(lst, lst + n);
	
	ll ans = L % MOD;
	for (int i = 0; i < n; ++i)
		dp[1][i] = 1;
	for (int i = 2; i <= K; ++i){
		ll (&f)[MAXN] = dp[i - 1 & 1];
		ll (&g)[MAXN] = dp[i & 1];
		ll sum = 0;
		for (int k = 0, j = 0; j < n; ++j){
			for (; k < n && lst[k].first <= lst[j].first; ++k)
				sum = (sum + f[k]) % MOD;
			g[j] = sum;
			ans = (ans + ((L - lst[j].second - 1) / n - i + 2) % MOD * sum) % MOD;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}