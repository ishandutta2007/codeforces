#include <cstdio>

const int MAXN = 3E5 + 10;

char s[MAXN];

int main(){
	scanf("%s", s);
	long long ans = 0;
	for (int i = 0; s[i]; ++i)
		ans += (s[i] - '0') % 4 == 0;
	for (int i = 1; s[i]; ++i)
		if (((s[i - 1] - '0') * 10 + s[i] - '0') % 4 == 0)
			ans += i;
	printf("%I64d\n", ans);
	return 0;
}