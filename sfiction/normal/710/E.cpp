#include <cstdio>
#include <algorithm>

const int MAXN = 1E7 + 10;

long long f[MAXN];

int main(){
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	f[1] = x;
	for (int i = 2; i <= n; ++i)
		f[i] = std::min(f[i - 1] + x, f[i + 1 >> 1] + y + (i & 1 ? x : 0));
	printf("%I64d\n", f[n]);
	return 0;
}