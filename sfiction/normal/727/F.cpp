#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1E3 + 10;

int n, q;
int a[MAXN];
ll f[MAXN][MAXN];

int main(){
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = n; i > 0; --i){
		f[i][n - i + 1] = 1ll << 60;
		f[i][0] = a[i] + min(0ll, f[i + 1][0]);
		for (int j = 1; j <= n - i; ++j)
			f[i][j] = max(a[i] + min(0ll, f[i + 1][j]), f[i + 1][j - 1]);
	}
	for (int i = 0; i < q; ++i){
		ll s;
		scanf("%lld", &s);
		printf("%d\n", lower_bound(f[1], f[1] + n, -s) - f[1]);
	}
	return 0;
}