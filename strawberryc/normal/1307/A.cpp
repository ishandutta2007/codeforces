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

const int N = 105;

int n, d, a[N];

void work()
{
	read(n); read(d);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= d; i++)
	{
		int x = 1;
		for (int j = 2; j <= n; j++)
			if (a[j]) {x = j; break;}
		if (x == 1) break;
		a[x - 1]++; a[x]--;
	}
	printf("%d\n", a[1]);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}