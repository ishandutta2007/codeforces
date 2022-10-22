#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 1e5 + 5, M = N << 1;

int n[3], nxt[M], a[3][3];
char s[3][N], S[M];
bool is[3];

bool substr(int n, char *s, int m, char *t)
{
	nxt[1] = 0;
	for (int i = 2, j = 0; i <= m; i++)
	{
		while (j && t[j + 1] != t[i]) j = nxt[j];
		if (t[j + 1] == t[i]) j++;
		nxt[i] = j;
	}
	for (int i = 1, j = 0; i <= n; i++)
	{
		while (j && t[j + 1] != s[i]) j = nxt[j];
		if (t[j + 1] == s[i]) j++;
		if (j == m) return 1;
	}
	return 0;
}

int orz_zzq(int n, char *s, int m, char *t)
{
	nxt[1] = 0;
	for (int i = 1; i <= m; i++) S[i] = t[i];
	for (int i = 1; i <= n; i++) S[m + i] = s[i];
	for (int i = 2, j = 0; i <= n + m; i++)
	{
		while (j && S[j + 1] != S[i]) j = nxt[j];
		if (S[j + 1] == S[i]) j++;
		nxt[i] = j;
	}
	int res = n + m;
	while (res > Min(n, m)) res = nxt[res];
	return res;
}

int main()
{
	scanf("%s%s%s", s[0] + 1, s[1] + 1, s[2] + 1);
	n[0] = strlen(s[0] + 1);
	n[1] = strlen(s[1] + 1);
	n[2] = strlen(s[2] + 1);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if ((n[j] > n[i] || (n[j] == n[i] && j < i))
				&& substr(n[j], s[j], n[i], s[i]))
					is[i] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (i != j) a[i][j] = orz_zzq(n[i], s[i], n[j], s[j]);
	if ((!is[0]) + (!is[1]) + (!is[2]) == 1)
		for (int i = 0; i < 3; i++)
			if (!is[i]) return std::cout << n[i] << std::endl, 0;
	if (is[0]) return std::cout << n[1] + n[2] -
		Max(a[1][2], a[2][1]) << std::endl, 0;
	if (is[1]) return std::cout << n[0] + n[2] -
		Max(a[0][2], a[2][0]) << std::endl, 0;
	if (is[2]) return std::cout << n[0] + n[1] -
		Max(a[0][1], a[1][0]) << std::endl, 0;
	int res = 0;
	res = Max(res, a[0][1] + a[1][2]);
	res = Max(res, a[0][2] + a[2][1]);
	res = Max(res, a[1][0] + a[0][2]);
	res = Max(res, a[1][2] + a[2][0]);
	res = Max(res, a[2][0] + a[0][1]);
	res = Max(res, a[2][1] + a[1][0]);
	std::cout << n[0] + n[1] + n[2] - res << std::endl;
	return 0;
}