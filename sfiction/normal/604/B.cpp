#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 10;

int a[MAXN];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int ans = a[n];
	if (k < n){
		int m = n - k << 1 | 1;
		for (int i = m >> 1; i >= 1; --i)
			ans = max(ans, a[i] + a[m - i]);
	}
	printf("%d\n", ans);
	return 0;
}