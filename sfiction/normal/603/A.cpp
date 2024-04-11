#include <cstdio>

const int MAXN = 1E5 + 10;

char s[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int cnt = 3;
	for (int i = 1; i < n; ++i)
		cnt += s[i] != s[i - 1];
	printf("%d\n", cnt < n ? cnt : n);
	return 0;
}