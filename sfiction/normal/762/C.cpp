#include <cstdio>
#include <cstring>

const int MAXL = 1E5 + 10;

char a[MAXL], b[MAXL];
int pre[MAXL], suf[MAXL];

int main(){
	scanf("%s%s", a + 1, b + 1);
	int n = strlen(a + 1), m = strlen(b + 1);
	pre[0] = 0;
	for (int j, i = 1; i <= m; ++i){
		for (j = pre[i - 1] + 1; j <= n && a[j] != b[i]; ++j);
		pre[i] = j;
	}
	suf[m + 1] = n + 1;
	for (int j, i = m; i >= 1; --i){
		for (j = suf[i + 1] - 1; j >= 1 && a[j] != b[i]; --j);
		suf[i] = j;
	}

	int ans = m, l = 1, r = m;
	for (int j = 0, i = 0; i <= m && pre[i] <= n; ++i){
		for (; j <= i || pre[i] >= suf[j]; ++j);
		if (j - i - 1 <= ans)
			ans = j - i - 1, l = i + 1, r = j - 1;
	}
	if (ans == m)
		puts("-");
	else{
		for (int i = 1; i <= m; ++i)
			if (i < l || r < i)
				putchar(b[i]);
		puts("");
	}
	return 0;
}