#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 255, M = 26, L = N << 1, ZZQ = 998244353, YSY = 1e9 + 7;

int n, m, h1[N][N][N], h2[N][N][N], pw1[M], pw2[M], str1[L], str2[L],
ans, R[L], cnt[M];
char s[N][N];
bool pal[N][N][N];

void manacher(int n)
{
	int i, mx = 0, pos;
	For (i, 1, n)
	{
		R[i] = mx > i ? Min(mx - i, R[(pos << 1) - i]) : 1;
		while (str1[i - R[i]] == str1[i + R[i]]
			&& str2[i - R[i]] == str2[i + R[i]]) R[i]++;
		if (i + R[i] > mx) mx = i + R[i], pos = i;
	}
}

void solve(int l, int r)
{
	int i, tot = 0;
	str1[0] = str2[0] = -19310918;
	For (i, 1, n)
	{
		str1[++tot] = -19370707;
		str2[tot] = -19370707;
		str1[++tot] = h1[i][l][r];
		str2[tot] = pal[i][l][r] ? h2[i][l][r] : -i;
	}
	str1[++tot] = -19370707;
	str2[tot] = -19370707;
	str1[tot + 1] = str2[tot + 1] = -19450815;
	manacher(tot);
	For (i, 1, tot)
		if (str2[i] < -1000 || str2[i] >= 0)
			ans += i & 1 ? R[i] - 1 >> 1 : R[i] >> 1;
}

int main()
{
	int i, j, k;
	std::cin >> n >> m;
	pw1[0] = pw2[0] = 1;
	For (i, 1, 25)
	{
		pw1[i] = 317ll * pw1[i - 1] % ZZQ;
		pw2[i] = 317ll * pw2[i - 1] % YSY;
	}
	For (i, 1, n) scanf("%s", s[i] + 1);
	For (i, 1, n) For (j, 1, m)
	{
		int o1 = 0, o2 = 0, cc = 0;
		For (k, 0, 25) cnt[k] = 0;
		For (k, j, m)
		{
			int c = s[i][k] - 'a';
			o1 = (o1 + pw1[c]) % ZZQ;
			o2 = (o2 + pw2[c]) % YSY;
			if ((++cnt[c]) & 1) cc++;
			else cc--;
			pal[i][j][k] = cc <= 1;
			h1[i][j][k] = o1; h2[i][j][k] = o2;
		}
	}
	For (i, 1, m) For (j, i, m) solve(i, j);
	std::cout << ans << std::endl;
	return 0;
}