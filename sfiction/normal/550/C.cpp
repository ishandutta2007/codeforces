/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 550C
 */
#include <cstdio>
#include <cstring>

const int MAXN = 1E2 + 10;

char s[MAXN];

int main(){
	s[0] = s[1] = '0';
	scanf("%s", s + 2);
	int ans = -1;
	for (char *p = s; *p; ++p)
		for (char *q = p + 1; *q; ++q)
			for (char *r = q + 1; *r; ++r){
				int t = (*p - '0') * 100 + (*q - '0') * 10 + (*r - '0');
				if (t % 8 == 0){
					ans = t;
					goto done;
				}
			}
done:
	if (~ans)
		printf("YES\n%d\n", ans);
	else
		puts("NO");
	return 0;
}