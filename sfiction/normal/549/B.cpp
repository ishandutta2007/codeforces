/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 549B
 */
#include <cstdio>
#include <cstring>

const int MAXN = 1E2 + 10;

int n;
char s[MAXN][MAXN];
int a[MAXN];

bool in[MAXN];

int main(){
	scanf("%d", &n);
	for (int i=0;i<n;++i){
		scanf("%s", s[i]);
		for (int j=0;j<n;++j)
			s[i][j] -= '0';
	}
	for (int i=0;i<n;++i)
		scanf("%d", &a[i]);

	memset(in, false, sizeof(in));
	int cntIn = 0;
	while (cntIn < n){
		int m = 0;
		for (; m < n && (in[m] || a[m]); ++m);
		if (m == n)
			break;

		in[m] = true;
		++cntIn;

		for (int i=0;i<n;++i)
			if (s[m][i])
				--a[i];
	}

	printf("%d", cntIn);
	bool flag = 0;
	for (int i=0;i<n;++i)
		if (in[i])
			printf("%c%d", flag ? ' ' : (flag = true, '\n'), i + 1);

	return 0;
}