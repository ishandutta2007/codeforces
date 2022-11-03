#include <cstdio>

const int MAXN = 1E2 + 10;

int n, m, K;
int a[MAXN];

int getItem(int t){
	int i = 1;
	for (; i <= K && a[i] != t; ++i);
	for (int j = i; j > 1; --j)
		a[j] = a[j - 1];
	a[1] = t;
	return i;
}

int main(){
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= K; ++i){
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int t, i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			scanf("%d", &t);
			ans += getItem(t);
		}
	}
	printf("%d\n", ans);
	return 0;
}