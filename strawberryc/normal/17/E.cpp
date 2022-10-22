#include <bits/stdc++.h>

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;

const int N = 4e6 + 10, rqy = 51123987;

int n, m, ans, R[N], id, mx, tmp[N], cnt[N], f[N], g[N], sum;
ll cnts;
char t[N], s[N]; 

int main()
{
	scanf("%d%s", &m, t + 1);
	s[0] = '@';
	for (int i = 1; i <= m; i++) s[++n] = '&', s[++n] = t[i];
	s[++n] = '&'; s[n + 1] = '*';
	for (int i = 1; i <= n; i++)
	{
		R[i] = mx > i ? Min(mx - i, R[(id << 1) - i]) : 0;
		while (s[i - R[i]] == s[i + R[i]]) R[i]++;
		if (i + R[i] > mx) mx = i + R[i], id = i;
		cnts += R[i] >> 1;
	}
	if (cnts & 1) sum = (cnts - 1) / 2 % rqy * (cnts % rqy) % rqy;
	else sum = cnts / 2 % rqy * ((cnts - 1) % rqy) % rqy;
	for (int i = 1; i <= n; i++) f[i]++, f[i + R[i]]--;
	for (int i = 1; i <= n; i++) f[i] += f[i - 1];
	for (int i = 1; i <= n; i++) cnt[i]++, cnt[i - R[i]]--;
	int cur = -1;
	for (int i = n; i >= 1; i--)
	{
		cur += cnt[i]; g[i] = g[i + 1];
		if (!(n - i & 1)) g[i] = (g[i] + cur) % rqy;
	}
	for (int i = 1; i <= n; i += 2)
		ans = (1ll * (f[i] + rqy - 1) * g[i] + ans) % rqy;
	return std::cout << (sum - ans + rqy) % rqy << std::endl, 0;
}