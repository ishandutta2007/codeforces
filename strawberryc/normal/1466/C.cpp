#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 1e5 + 5, INF = 0x3f3f3f3f;

int n, f[26][26], g[26][26];
char s[N];

void work()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	if (n == 1) return (void) puts("0");
	for (int c = 0; c < 26; c++)
		for (int d = 0; d < 26; d++)
			f[d][c] = c == d ? INF : (s[1] != c + 'a') + (s[2] != d + 'a');
	for (int i = 3; i <= n; i++)
	{
		for (int c = 0; c < 26; c++)
		{
			int gl = INF, gr = INF;
			for (int d = 0; d < 26; d++)
				if (f[c][d] < gl) gr = gl, gl = f[c][d];
				else if (f[c][d] < gr) gr = f[c][d];
			for (int d = 0; d < 26; d++)
				g[c][d] = f[c][d] == gl ? gr : gl;
		}
		for (int c = 0; c < 26; c++)
			for (int d = 0; d < 26; d++) if (c != d)
				f[c][d] = Min(INF, g[d][c] + (c + 'a' != s[i]));
	}
	int res = INF;
	for (int c = 0; c < 26; c++) for (int d = 0; d < 26; d++)
		res = Min(res, f[c][d]);
	printf("%d\n", res);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}