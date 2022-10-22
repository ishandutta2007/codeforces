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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 3e5 + 5;

int n, k, fa[N], val[N], is[N], cnt[N][2], tot[N], a[N][2], ans;
char s[N];

int cx(int x)
{
	if (fa[x] == x) return fa[x];
	int y = cx(fa[x]); val[x] ^= val[fa[x]];
	return fa[x] = y;
}

int getans(int x)
{
	if (is[x] == -1) return Min(cnt[x][0], cnt[x][1]);
	return cnt[x][is[x]];
}

void zm(int x, int y, int i)
{
	int ix = cx(x), iy = cx(y);
	if (ix == iy) return; fa[iy] = ix;
	ans -= getans(ix) + getans(iy);
	if (val[iy] = i ^ val[x] ^ val[y])
		cnt[ix][0] += cnt[iy][1], cnt[ix][1] += cnt[iy][0];
	else cnt[ix][0] += cnt[iy][0], cnt[ix][1] += cnt[iy][1];
	if (is[ix] == -1 && is[iy] != -1) is[ix] = is[iy] ^ val[iy];
	ans += getans(ix);
}

void fix(int x, int i)
{
	int ix = cx(x); ans -= getans(ix);
	is[ix] = i ^ val[x]; ans += getans(ix);
}

int main()
{
	read(n); read(k);
	scanf("%s", s + 1);
	for (int i = 1; i <= k; i++)
	{
		int t, x; read(t); fa[i] = i; cnt[i][1] = 1; is[i] = -1;
		while (t--) read(x), a[x][tot[x]++] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		if (tot[i] == 1) fix(a[i][0], s[i] == '0');
		else if (tot[i] == 2) zm(a[i][0], a[i][1], s[i] == '0');
		printf("%d\n", ans);
	}
	return 0;
}