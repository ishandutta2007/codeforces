#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2E5 + 10;

int a[MAXN];
int pre[MAXN], suf[MAXN];

int main(){
	int n, k, x;
	scanf("%d%d%d", &n, &k, &x);
	long long y = 1;
	for (int j = k; j > 0; --j)
		y *= x;
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] | a[i];
	}
	for (int i = n; i > 0; --i)
		suf[i] = suf[i + 1] | a[i];

	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, pre[i - 1] | y * a[i] | suf[i + 1]);
	printf("%I64d\n", ans);
	return 0;
}