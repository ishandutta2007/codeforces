#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 3E3 + 10;

int n, a[MAXN], b[MAXN];
ll f[MAXN][MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), a[i] -= i;
	copy(a + 1, a + n + 1, b + 1);
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; ++i){
		ll t = f[i - 1][1];
		for (int j = 1; j <= n; ++j){
			t = min(t, f[i - 1][j]);
			f[i][j] = t + abs(a[i] - b[j]);
		}
	}
	ll ans = f[n][1];
	for (int i = 1; i <= n; ++i)
		ans = min(ans, f[n][i]);
	printf("%I64d\n", ans);
	return 0;
}