#include <cstdio>
#include <cstring>

const int MAXN = 2E5 + 10;

char a[MAXN], b[MAXN];

int main(){
	scanf("%s%s", a, b);
	int n = strlen(a), m = strlen(b);
	int len = m - n + 1;
	int cnt = 0;
	for (int i = 0; i < len - 1; ++i)
		cnt += b[i] == '1';
	long long ans = 0;
	for (int i = 0; i < n; ++i){
		cnt += b[i + len - 1] == '1';
		ans += a[i] == '1' ? len - cnt : cnt;
		cnt -= b[i] == '1';
	}
	printf("%I64d\n", ans);
	return 0;
}