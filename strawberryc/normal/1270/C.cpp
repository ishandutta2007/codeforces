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

typedef long long ll;

const int N = 1e5 + 5;

int n, a[N];

void work()
{
	ll sum = 0; int xo = 0;
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), sum += a[i], xo ^= a[i];
	puts("2");
	printf("%d %lld\n", xo, sum + xo);
	
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}