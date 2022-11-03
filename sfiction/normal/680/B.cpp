#include <cstdio>

const int MAXN = 1E2 + 10;

int t[MAXN];

int main(){
	int n, a;
	scanf("%d%d", &n, &a);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &t[i]);
	int ans = t[a];
	int r = 1;
	for (; 1 <= a - r && a + r <= n; ++r)
		if (t[a - r] == t[a + r])
			ans += t[a - r] << 1;
	for (; 1 <= a - r; ++r)
		ans += t[a - r];
	for (; a + r <= n; ++r)
		ans += t[a + r];
	printf("%d\n", ans);
	return 0;
}