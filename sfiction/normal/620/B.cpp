#include <cstdio>

const int MAXN = 1E6 + 10;

int cnt[MAXN] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
	for (int i = 10; i < MAXN; ++i)
		cnt[i] = cnt[i / 10] + cnt[i % 10];

	int a, b, ans = 0;
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; ++i)
		ans += cnt[i];
	printf("%d\n", ans);
	return 0;
}