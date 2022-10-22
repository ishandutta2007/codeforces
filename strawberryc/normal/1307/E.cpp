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

const int N = 5005, rqy = 1e9 + 7;

int n, tm, m, s[N], th[N][N], cl[N], cr[N], res, ans, cnt[N], len[N];
int cnt1[N], cnt2[N];

struct elem
{
	int pos, sop, col;
} a[N];

inline bool comp(elem a, elem b)
{
	return a.pos < b.pos;
}

int main()
{
	int x, y;
	read(n); read(tm);
	for (int i = 1; i <= n; i++) read(s[i]), th[s[i]][++len[s[i]]] = i;
	while (tm--)
	{
		read(x); read(y);
		if (th[x][y]) a[++m] = (elem) {th[x][y], th[x][len[x] - y + 1], x};
	}
	std::sort(a + 1, a + m + 1, comp);
	for (int i = 0; i <= m; i++)
	{
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		memset(cnt, 0, sizeof(cnt));
		for (int j = 1; j <= m; j++) if (i != j)
		{
			bool cant1 = j > i || a[j].col == a[i].col,
				cant2 = i && a[j].sop <= a[i].pos;
			if (cant1 && cant2) continue;
			if (!cant1 && cant2) cnt1[a[j].col]++;
			else if (cant1 && !cant2) cnt2[a[j].col]++;
			else cnt[a[j].col]++;
		}
		int mx = i > 0, delta = 1;
		for (int j = 1; j <= n; j++)
			if (!cnt[j]) mx += cnt1[j] > 0, mx += cnt2[j] > 0,
				delta = 1ll * delta * std::max(cnt1[j], 1) % rqy
					* std::max(cnt2[j], 1) % rqy;
			else if (cnt[j] >= 2)
			{
				mx += 2;
				int add = 1ll * cnt[j] * (cnt[j] - 1) % rqy;
				add = (1ll * (cnt1[j] + cnt2[j]) * cnt[j] + add) % rqy;
				add = (1ll * cnt1[j] * cnt2[j] + add) % rqy;
				delta = 1ll * delta * add % rqy;
			}
			else if (!cnt1[j] && !cnt2[j]) mx++,
				delta = 2ll * delta % rqy;
			else if (cnt1[j] && !cnt2[j]) mx += 2, delta = 1ll * delta * cnt1[j] % rqy;
			else if (!cnt1[j] && cnt2[j]) mx += 2, delta = 1ll * delta * cnt2[j] % rqy;
			else
			{
				mx += 2;
				int add = 1ll * cnt1[j] * cnt2[j] % rqy;
				add = (add + cnt1[j] + cnt2[j]) % rqy;
				delta = 1ll * delta * add % rqy;
			}
		if (mx > res) res = mx, ans = delta;
		else if (mx == res) ans = (ans + delta) % rqy;
	}
	return std::cout << res << " " << ans << std::endl, 0;
}