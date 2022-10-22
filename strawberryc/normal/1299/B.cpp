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

int n, X[N], Y[N];

ll calc(int i, int j, int k)
{
	return 1ll * (X[i] - X[k]) * (Y[j] - Y[k])
		- 1ll * (X[j] - X[k]) * (Y[i] - Y[k]);
}

ll dist(int i, int j)
{
	return 1ll * (X[i] - X[j]) * (X[i] - X[j])
		+ 1ll * (Y[i] - Y[j]) * (Y[i] - Y[j]);
}

int nxt(int i) {return i % n + 1;}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(X[i]), read(Y[i]);
	if (n & 1) return puts("no"), 0;
	for (int i = 1; i <= (n >> 1); i++)
	{
		int j = i + 1, k = i + (n >> 1), h = k % n + 1;
		if (calc(i, j, k) != calc(i, j, h) ||
			dist(i, j) != dist(k, h)) return puts("no"), 0;
	}
	puts("yes");
	return 0;
}