#include <cstdio>

const int MAXN = 2E5 + 10;
const long long INF = 1ll << 50;

int a[MAXN], b[MAXN];

int main(){
	int n, K;
	scanf("%d%d", &n, &K);
	for (int t, i = 0; i <= n; ++i){
		scanf("%d", &b[i]);
		a[i] += b[i];
		a[i + 1] += a[i] >> 1;
		a[i] &= 1;
	}

	int l = 0;
	for (; a[l] == 0; ++l);
	if (l > n)
		l = n;

	long long s = 0;
	int ans = 0;
	for (int i = n + 1; i >= 0; --i){
		s <<= 1;
		s += a[i];
		if (s > INF)
			s = INF;
		else if (s < -INF)
			s = -INF;

		if (i <= l && (i < n || i == n && b[i] != s) && -K <= b[i] - s && b[i] - s <= K)
			++ans;
	}
	printf("%d\n", ans);
	return 0;
}