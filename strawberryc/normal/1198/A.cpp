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

const int N = 4e5 + 5, INF = 0x3f3f3f3f;

int n, I, a[N], m = 1, ans, tot, sum[N];

int main()
{
	read(n); read(I); I <<= 3; I /= n;
	for (int i = 1; i <= n; i++) read(a[i]);
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= I; i++)
		if ((m << 1) >= n) {m = n; break;}
		else m <<= 1;
	for (int i = 1; i <= n; i++)
		if (i == 1 || a[i] != a[i - 1]) sum[++tot] = 1;
		else sum[tot]++;
	for (int i = 1; i <= tot; i++) sum[i] += sum[i - 1];
	for (int i = 1; i <= tot; i++)
		ans = std::max(ans, sum[i] - sum[std::max(0, i - m)]);
	return std::cout << n - ans << std::endl, 0;
}