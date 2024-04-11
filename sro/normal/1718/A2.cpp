#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
int a[100005], p[100005];
int dp[100005];
map<int, int> pre;

void solve() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", a + i);
	int ps = 0;
	for (int i = 0; i < N; ++i) p[i] = ps, ps ^= a[i];
	p[N] = ps;
	pre.clear();
	for (int i = 0; i <= N + 1; ++i) dp[i] = N;
	for (int i = N; ~i; --i) {
		dp[i] = dp[i + 1];
		if (pre.count(p[i])) dp[i] = min(dp[i], dp[pre[p[i]]] - 1);
		pre[p[i]] = i;
	}
	printf("%d\n", dp[0]);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}