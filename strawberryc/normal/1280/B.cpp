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

const int N = 63;

int n, m;
char s[N][N];
bool allx[N], ally[N];

void work()
{
	read(n); read(m); bool is = 1;
	memset(allx, true, sizeof(allx)); memset(ally, true, sizeof(ally));
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; j++)
			if (s[i][j] == 'P') allx[i] = ally[j] = 0, is = 0;
	}
	if (is) return (void) puts("0");
	if (allx[1] || allx[n] || ally[1] || ally[m]) return (void) puts("1");
	for (int i = 1; i <= n; i++) if (allx[i]) return (void) puts("2");
	for (int i = 1; i <= m; i++) if (ally[i]) return (void) puts("2");
	if (s[1][1] == 'A' || s[1][m] == 'A' || s[n][1] == 'A' || s[n][m] == 'A')
		return (void) puts("2");
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		if ((i == 1 || j == 1 || i == n || j == m) && s[i][j] == 'A')
			return (void) puts("3");
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		if (s[i][j] == 'A') return (void) puts("4");
	puts("MORTAL");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}