#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 2E5 + 10;

int n, K, S, T;
int v[MAXN], c[MAXN];
int a[MAXN];
int s[MAXN];

int main(){
	scanf("%d%d%d%d", &n, &K, &S, &T);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", c + i, v + i);
	for (int i = 1; i <= K; ++i)
		scanf("%d", a + i);
	a[++K] = S;
	sort(a + 1, a + K + 1);
	for (int i = K; i > 0; --i)
		a[i] -= a[i - 1];
	sort(a + 1, a + K + 1);
	for (int i = 1; i <= K; ++i)
		s[i] = s[i - 1] + a[i];
	
	const int INF = 2E9;
	int ans = INF;
	for (int i = 1; i <= n; ++i){
		if (a[K] > v[i])
			continue;

		int r = lower_bound(a + 1, a + K + 1, v[i] + 1 >> 1) - a - 1;
		ll cost = s[r] + (s[K] - s[r]) * 3ll - (ll)(K - r) * v[i];
		if (cost <= T)
			ans = min(ans, c[i]);
	}
	printf("%d\n", ans == INF ? -1 : ans);
	return 0;
}