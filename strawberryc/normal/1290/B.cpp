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

const int N = 2e5 + 5;

int n, q, sum[26][N];
char s[N];

int main()
{
	int l, r;
	scanf("%s", s + 1); n = strlen(s + 1);
	read(q);
	for (int c = 0; c < 26; c++)
		for (int i = 1; i <= n; i++)
			sum[c][i] = sum[c][i - 1] + (s[i] == c + 'a');
	while (q--)
	{
		read(l); read(r);
		int cnt = 0;
		for (int c = 0; c < 26; c++)
			if (sum[c][r] != sum[c][l - 1]) cnt++;
		if (l == r) puts("Yes");
		else if (cnt == 1) puts("No");
		else if (cnt > 2) puts("Yes");
		else puts(s[l] == s[r] ? "No" : "Yes");
	}
	return 0;
}