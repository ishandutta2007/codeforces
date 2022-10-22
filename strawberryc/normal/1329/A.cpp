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

int n, m, l[N], cnt[N], ans[N];
ll sum;

int main()
{
	read(n); read(m);
	for (int i = 1; i <= m; i++) read(l[i]), sum += l[i], cnt[i] = 1;
	if (sum < n) return puts("-1"), 0;
	if (m - 1 + l[m] > n) return puts("-1"), 0;
	cnt[m] = l[m];
	for (int i = m - 1, j = n - l[m] - (m - 1); i >= 1; i--)
		if (j > l[i] - 1) j -= l[i] - 1, cnt[i] = l[i];
		else cnt[i] += j, j = 0;
	ans[1] = 1;
	for (int i = 1, j = cnt[1]; i < m; i++, j += cnt[i])
		ans[i + 1] = j + 1;
	for (int i = 1; i <= m; i++) if (ans[i] > n - l[i] + 1)
		return puts("-1"), 0;
	for (int i = 1; i <= m; i++) printf("%d ", ans[i]); 
	return puts(""), 0;
}