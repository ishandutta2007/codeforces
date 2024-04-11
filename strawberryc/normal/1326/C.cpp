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

const int N = 2e5 + 5, djq = 998244353;

int n, k, p[N], ans = 1, q[N];
ll res;

inline bool comp(int a, int b) {return p[a] > p[b];}

int main()
{
	read(n); read(k);
	for (int i = 1; i <= n; i++) read(p[i]), q[i] = i;
	std::sort(q + 1, q + n + 1, comp);
	for (int i = 1; i <= k; i++) res += p[q[i]];
	std::sort(q + 1, q + k + 1);
	for (int i = 1; i < k; i++) ans = 1ll * ans * (q[i + 1] - q[i]) % djq;
	return std::cout << res << " " << ans << std::endl, 0;
}