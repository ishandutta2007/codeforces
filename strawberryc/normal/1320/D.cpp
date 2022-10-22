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

const int N = 2e5 + 5, djq = 1e9 + 7, zyy = 1e9 + 9;

int n, q, sum[N], fi[N], ls[N], m, th[N], pos[N], pd[N], pz[N], sd[N], sz[N];
char s[N];

int h1(int l, int r)
{return (sd[r] - 1ll * sd[l - 1] * pd[r - l + 1] % djq + djq) % djq;}

int h2(int l, int r)
{return (sz[r] - 1ll * sz[l - 1] * pz[r - l + 1] % zyy + zyy) % zyy;}

int main()
{
	int l1, l2, l;
	read(n);
	scanf("%s", s + 1);
	read(q);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i] == '0');
	for (int i = 1; i <= n; i++) ls[i] = s[i] == '0' ? i : ls[i - 1];
	for (int i = n; i >= 1; i--) fi[i] = s[i] == '0' ? i : fi[i + 1];
	for (int i = 1; i <= n; i++) if (s[i] == '0') pos[th[i] = ++m] = i;
	pd[0] = pz[0] = 1;
	for (int i = 1; i <= n; i++) pd[i] = 3ll * pd[i - 1] % djq,
		pz[i] = 3ll * pz[i - 1] % zyy;
	for (int i = 1; i < m; i++)
	{
		sd[i] = 3ll * sd[i - 1] % djq; sz[i] = 3ll * sz[i - 1] % zyy;
		if (pos[i + 1] - pos[i] - 1 & 1) sd[i] = (sd[i] + 1) % djq,
			sz[i] = (sz[i] + 1) % zyy;
	}
	while (q--)
	{
		read(l1); read(l2); read(l);
		int r1 = l1 + l - 1, r2 = l2 + l - 1;
		if (sum[r1] - sum[l1 - 1] != sum[r2] - sum[l2 - 1])
			{puts("No"); continue;}
		if (sum[r1] == sum[l1 - 1]) {puts("Yes"); continue;}
		if ((fi[l1] - l1 & 1) ^ (fi[l2] - l2 & 1)) {puts("No"); continue;}
		if ((r1 - ls[r1] & 1) ^ (r2 - ls[r2] & 1)) {puts("No"); continue;}
		puts(h1(th[fi[l1]], th[ls[r1]] - 1) == h1(th[fi[l2]], th[ls[r2]] - 1) &&
			h2(th[fi[l1]], th[ls[r1]] - 1) == h2(th[fi[l2]], th[ls[r2]] - 1)
				? "Yes" : "No");
	}
	return 0;
}