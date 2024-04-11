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

const int N = 22;

int n, m, ls[N], lt[N], q;
char s[N][N], t[N][N];

int main()
{
	int x;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%s", s[i] + 1), ls[i] = strlen(s[i] + 1);
	for (int i = 0; i < m; i++)
		scanf("%s", t[i] + 1), lt[i] = strlen(t[i] + 1);
	std::cin >> q;
	while (q--)
	{
		read(x); x--;
		for (int i = 1; i <= ls[x % n]; i++) putchar(s[x % n][i]);
		for (int i = 1; i <= lt[x % m]; i++) putchar(t[x % m][i]);
		puts("");
	}
	return 0;
}