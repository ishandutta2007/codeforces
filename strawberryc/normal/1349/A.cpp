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

const int N = 2e5 + 5;

int n, a[N], tot, p[N], q[N];
std::vector<int> cnt[N];
ll ans = 1;

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]); int S = sqrt(a[i]);
		tot = 0;
		for (int j = 2; j <= S; j++)
		{
			if (a[i] % j) continue;
			p[++tot] = j; q[tot] = 0;
			while (a[i] % j == 0) a[i] /= j, q[tot]++;
		}
		if (a[i] > 1) p[++tot] = a[i], q[tot] = 1;
		for (int j = 1; j <= tot; j++) cnt[p[j]].push_back(q[j]);
	}
	for (int i = 1; i <= 200000; i++) std::sort(cnt[i].begin(), cnt[i].end());
	for (int i = 1; i <= 200000; i++)
		if (cnt[i].size() + 1 == n)
			for (int j = 1; j <= cnt[i][0]; j++) ans *= i;
		else if (cnt[i].size() == n)
			for (int j = 1; j <= cnt[i][1]; j++) ans *= i; 
	return std::cout << ans << std::endl, 0;
}