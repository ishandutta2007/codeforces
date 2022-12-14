#include <cstdio>
#include <cstring>

#define N 100005

char s[N], t[N];
char a[N], b[N];

bool isok(char *x) {
	int len = strlen(x);
	if (!len) return 0;
	if (x[0] == '0') {
		if (len == 1) return 1;
		return 0;
	}
	for (int i = 0; i < len; i ++) {
		if (x[i] < '0' || '9' < x[i]) return 0;
	}
	return 1;
}

main() {
	gets(s);
	int len = 0, la = 0, lb = 0;
	for (int i = 0; ; i ++) {
		if (s[i] == ',' || s[i] == ';' || s[i] == 0) {
			t[len] = 0;
			if (isok(t)) {
				if (!la) a[la ++] = '\"';
				else a[la ++] = ',';
				for (int j = 0; t[j]; j ++) a[la ++] = t[j];
			} else {
				if (!lb) b[lb ++] = '\"';
				else b[lb ++] = ',';
				for (int j = 0; t[j]; j ++) b[lb ++] = t[j];
			}
			len = 0;
		} else t[len ++] = s[i];
		if (s[i] == 0) break;
	}
	a[la ++] = '\"', b[lb ++] = '\"';
	a[la] = b[lb] = 0;
	puts(la > 1 ? a : "-");
	puts(lb > 1 ? b : "-");
}