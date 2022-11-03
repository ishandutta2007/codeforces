#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E2 + 10;

int a[2][MAXN], b[MAXN];
int sum[2][MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
		scanf("%d", &a[0][i]);
	for (int i = 1; i < n; ++i)
		scanf("%d", &a[1][i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	for (int i = 1; i < n; ++i)
		sum[0][i] = sum[0][i - 1] + a[0][i];
	for (int i = n - 1; i > 0; --i)
		sum[1][i] = sum[1][i + 1] + a[1][i];

	int m = sum[0][0] + sum[1][1] + b[0];
	int ans = 0X7fffffff;
	for (int t, i = 1; i < n; ++i){
		t = sum[0][i] + sum[1][i + 1] + b[i];
		ans = min(ans, m + t);
		m = min(m, t);
	}
	printf("%d\n", ans);
	return 0;
}