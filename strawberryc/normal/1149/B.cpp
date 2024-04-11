#include <bits/stdc++.h>

// 0830
//

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

inline char get()
{
	char c;
	while ((c = getchar()) != '+' && c != '-');
	return c;
}

inline char getcc()
{
	char c;
	while ((c = getchar()) < 'a' || c > 'z');
	return c;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 2e5 + 5, M = 255;

int n, q, len[4], nxt[N][26], lst[26], f[M][M][M];
char s[N], a[4][M];

int trans(int i, int j, int k)
{
	f[i][j][k] = n + 1;
	if (i) f[i][j][k] = Min(f[i][j][k], nxt[f[i - 1][j][k]][a[1][i] - 'a']);
	if (j) f[i][j][k] = Min(f[i][j][k], nxt[f[i][j - 1][k]][a[2][j] - 'a']);
	if (k) f[i][j][k] = Min(f[i][j][k], nxt[f[i][j][k - 1]][a[3][k] - 'a']);
}

int main()
{
	n = read(); q = read();
	scanf("%s", s + 1);
	for (int c = 0; c < 26; c++) lst[c] = nxt[n + 1][c] = n + 1;
	for (int i = n; i >= 0; i--)
	{
		for (int c = 0; c < 26; c++) nxt[i][c] = lst[c];
		if (i) lst[s[i] - 'a'] = i;
	}
	while (q--)
	{
		char op = get(); int th = read();
		if (op == '+')
		{
			char c = getcc();
			a[th][++len[th]] = c;
			if (th == 1)
				for (int j = 0; j <= len[2]; j++)
					for (int k = 0; k <= len[3]; k++)
						trans(len[1], j, k);
			if (th == 2)
				for (int j = 0; j <= len[1]; j++)
					for (int k = 0; k <= len[3]; k++)
						trans(j, len[2], k);
			if (th == 3)
				for (int j = 0; j <= len[1]; j++)
					for (int k = 0; k <= len[2]; k++)
						trans(j, k, len[3]);
		}
		else len[th]--;
		puts(f[len[1]][len[2]][len[3]] <= n ? "YES" : "NO");
	}
	return 0;
}