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

const int N = 2005;

int n, k, m, l[N], r[N];
char s[N], tar[N];

void work()
{
	read(n); read(k);
	scanf("%s", s + 1);
	for (int i = 1; i < k; i++)
		tar[i * 2 - 1] = '(', tar[i * 2] = ')';
	for (int i = 1; i <= n / 2 - k + 1; i++)
		tar[(k - 1) * 2 + i] = '(', tar[(k - 1) * 2 + n / 2 - k + 1 + i] = ')';
	m = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == tar[i]) continue;
		int p;
		for (int j = i; j <= n; j++)
			if (s[j] == tar[i]) p = j;
		l[++m] = i; r[m] = p;
		for (int j = i, k = p; j < k; j++, k--) std::swap(s[j], s[k]);
	}
	printf("%d\n", m);
	for (int i = 1; i <= m; i++) printf("%d %d\n", l[i], r[i]);
}
int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}