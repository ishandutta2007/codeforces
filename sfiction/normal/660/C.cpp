#include <cstdio>

const int MAXN = 3E5 + 10;

int a[MAXN];

int main(){
	int n, K;
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int ans = -1, cnt = 0, L = 1, R = 0;
	int l = 1;
	for (int l = 1, i = 1; i <= n; ++i){
		cnt += !a[i];
		for (; K < cnt; cnt -= !a[l++]);
		if (ans < i - l + 1){
			ans = i - l + 1;
			L = l, R = i;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", a[i] || L <= i && i <= R, "\n "[i < n]);
	return 0;
}