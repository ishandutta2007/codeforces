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

const int N = 3e5 + 5;

int n, m, c[N], cnt[N], cs[N], cm[N];
ll sum[N];

void work()
{
	int k, al; ll cur = 0, ans = 1e18;
	read(n); read(m); al = m; int now = n;
	for (int i = 1; i <= m; i++) cnt[i] = 1;
	for (int i = 1; i <= n; i++) read(k), cnt[k]--, al--;
		cs[m + 1] = cm[m + 1] = 0;
	for (int i = 1; i <= m; i++) read(c[i]), sum[i] = sum[i - 1] + c[i];
	for (int i = m; i >= 1; i--) cs[i] = cs[i + 1] + cnt[i],
		cm[i] = std::max(cm[i + 1], cs[i]);
	if (al >= cm[1]) ans = sum[n];
	for (int i = 1; i <= m; i++)
		while (cnt[i] < 1)
		{
			cur += c[i]; al++;
			cnt[i]++; cs[i]++; cm[i] = std::max(cm[i], cs[i]); now--;
			if (al >= cm[i]) ans = std::min(ans, sum[now] + cur);
		}
	printf("%lld\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}