#include <cstdio>

#define N 100100

int n, m;
char s[N];

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	int l = 1;
	for(int i = 1; i < n; i ++) if(s[i] != s[i-1]) l ++;
	long long ans = 1LL * l * n * (m - 1);
	for(int i = 0, j; i < n - 1; i ++) if(s[i] != s[i+1]) {
		for(j = i + 2; j < n; j ++) if(s[j] != s[j-2]) break;
		ans -= 1LL * (j - i) * (j - i - 1) / 2;
		i = j - 2;
	}
	printf("%I64d\n", ans);
	return 0;
}