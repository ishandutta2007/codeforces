#include <cstdio>
#include <cstring>

#define L 10001000

void zAlgo(char *s, int *z) {
	int len = strlen(s);
	z[0] = len;
	for (int i = 1, j = 0; i < len; ) {
		while (i + j < len && s[j] == s[i + j]) j ++;
		z[i] = j;
		if (!j) {
			i ++;
			continue;
		}
		int k = 1;
		while (i + k < len && k + z[k] < j) z[i + k] = z[k], k ++;
		i += k, j -= k;
	}
}

int z[L], ans[L];
char s[L], t[L];

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%s", s);
	int len = strlen(s);
	strcpy(t, s); strrev(t);
	strcat(s, "&");
	strcat(s, t);
	zAlgo(s, z);
	ans[0] = 1;
	for (int i = 1; i < len; i ++) {
		if (z[2*len-i] >= i) ans[i] = ans[(i-1)>>1] + 1;
	}
	long long Ans = 0;
	for (int i = 0; i < len; i ++) Ans += ans[i];
	printf("%I64d\n", Ans);
	return 0;
}