#include <cstdio>

const int MAXN = 1E5 + 10;

int cnta[MAXN << 1], cntb[MAXN << 1];

int main(){
	int n;
	scanf("%d", &n);
	long long ans = 0;
	for (int x, y, i = 0; i < n; ++i){
		scanf("%d%d", &x, &y);
		ans += cnta[x + y]++;
		ans += cntb[x - y + MAXN]++;
	}
	printf("%I64d\n", ans);
	return 0;
}