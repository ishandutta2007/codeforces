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

const int N = 1e6 + 5, rqy = 1e9 + 7;

int x, n, len;
char s[N];

void work()
{
	read(x); scanf("%s", s + 1); n = strlen(s + 1);
	len = n; bool be = 0;
	for (int i = 1; i <= x; i++)
	{
		int c = s[i] - '0', nlen = (1ll * (c - 1) * (len - i + rqy) + len) % rqy;
		if (!be) for (int j = len + 1; j <= nlen && j <= x; j++)
			s[j] = s[j - len + i];
		if (nlen >= x) be = 1;
		len = nlen;
	}
	printf("%d\n", len);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}