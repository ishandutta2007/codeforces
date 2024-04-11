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

const int N = 1e6 + 5;

int n, q, b[N], st, ed, tot, A[N], B[N], maxb;

int main()
{
	ll m;
	read(n); read(q);
	for (int i = 1; i <= n; i++)
	{
		read(b[i]);
		if (b[i] > maxb) maxb = b[i];
	}
	st = 1; ed = n;
	while (b[st] < maxb)
	{
		A[++tot] = b[st]; B[tot] = b[st + 1];
		if (b[st] > b[st + 1]) b[++ed] = b[st + 1], b[st + 1] = b[st], st++;
		else b[++ed] = b[st], st++;
	}
	while (q--)
	{
		read(m);
		if (m <= tot) printf("%d %d\n", A[m], B[m]);
		else printf("%d %d\n", maxb, b[st + 1 + (m - tot - 1) % (n - 1)]);
	}
	return 0;
}