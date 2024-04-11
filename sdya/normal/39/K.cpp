#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <vector>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n, m, t;
int xl[100], yl[100], xr[100], yr[100], nt, area[100];
char s[1100][1100];
int lt[1100][1100];
int up[1100][1100];
int dw[1100][1100];
int p[1100][1100];

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool used[1100][1100];

bool val(int x, int y) {return (0 <= x && x < n && 0 <= y && y < m);}

void dfs(int x, int y)
{
	if (used[x][y]) return ;
	used[x][y] = true;
	xl[nt] = min(x, xl[nt]), xr[nt] = max(x, xr[nt]);
	yl[nt] = min(y, yl[nt]), yr[nt] = max(y, yr[nt]);

	for (int i = 0; i < 4; i ++)
		if (val(x + dx[i], y + dy[i]) && s[x + dx[i]][y + dy[i]] == '*')
			dfs(x + dx[i], y + dy[i]);
}

int sum(int x, int y)
{
	if (x < 0 || y < 0) return 0;
	return p[x][y];
}

int sum(int x1, int y1, int x2, int y2)
{
	return p[x2][y2] - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
}

int nl[1100], nr[1100];
int a[1100];

int levo[1100], pravo[1100];
int ml[1100], mr[1100];
int sl[1100], sr[1100];

int getsum(int i, int r)
{
	if (r <= ml[i])
		return (r + 1) * levo[i];
	return (ml[i] + 1) * levo[i] + sr[r] - sr[ml[i]];
}

int getsum2(int i, int r)
{
	if (r <= mr[i])
		return (r + 1) * pravo[i];
	return (mr[i] + 1) * pravo[i] + sl[r] - sl[mr[i]];
}

long long solve(int x1, int y1, int x2, int y2)
{
	int segs = 0;
	if (y1 == 0)
	{
		//segs ++; nl[segs] = x1, nr[segs] = x2;
	} else
	{
		int sl = x1 - 1, sr = x2 + 1;
		int f = y2 - y1 + 1;
		while (sl >= 0)
		{
			if (lt[sl][y1 - 1] >= f + 1 && s[sl][y1 - 1] == '.') sl --; else break;
		}
		sl ++;
		while (sr < n)
		{
			if (lt[sr][y1 - 1] >= f + 1 && s[sr][y1 - 1] == '.') sr ++; else break;
		}
		sr --;
		if (up[sr][y1 - 1] >= sr - sl + 1) 
		{
			segs ++;
			nl[segs] = sl, nr[segs] = sr;
			for (int i = y1 - 2; i >= 0; i --)
			{
				int L = x1 - up[x1][i] + 1, R = x1 + dw[x1][i] - 1;
				if (L > x1 || R < x2) break;
				sl = max(sl, L), sr = min(sr, R);
				segs ++;
				nl[segs] = sl, nr[segs] = sr;
			}
		}
		//segs ++;
		//nl[segs] = x1, nr[segs] = x2;
	}

	int s1 = nl[1], s2 = nr[1];
	for (int i = s1; i <= s2; i ++)
		a[i] = lt[i][y2 + 1] + 1;

	int mn = 1000000;
	for (int i = x1; i <= x2; i ++)
		mn = min(mn, a[i]);

	int l1 = x1 - s1, l2 = s2 - x2;
	levo[0] = pravo[0] = mn;
	for (int i = 1; i <= l1; i ++)
		levo[i] = min(levo[i - 1], lt[x1 - i][y2 + 1] + 1);
	for (int i = 1; i <= l2; i ++)
		pravo[i] = min(pravo[i - 1], lt[x2 + i][y2 + 1] + 1);

	int v;
	v = 1;
	for (int i = 1; i <= l1; i ++)
	{
		while (v <= l2 && pravo[v] >= levo[i])
			v ++;
		ml[i] = v - 1;
	}
	v = 1;
	for (int i = 1; i <= l2; i ++)
	{
		while (v <= l1 && levo[v] >= pravo[i])
			v ++;
		mr[i] = v - 1;
	}

	sl[0] = sr[0] = mn;
	for (int i = 1; i <= l1; i ++)
		sl[i] = sl[i - 1] + levo[i];
	for (int i = 1; i <= l2; i ++)
		sr[i] = sr[i - 1] + pravo[i];

	long long res = 0;
	int cur = 0;
	for (int h = 1; h <= segs; h ++)
		if (h == 1)
		{
			//cur += sr[l2] + mn;
			for (int i = 0; i <= l1; i ++)
				cur += (ml[i] + 1) * levo[i] + (sr[l2] - sr[ml[i]]);
			res += (long long)(cur);
		} else
		{
			for (int i = nl[h - 1]; i < nl[h]; i ++)
				cur -= getsum(x1 - i, nr[h - 1] - x2);
			for (int i = nr[h - 1]; i > nr[h]; i --)
				cur -= getsum2(i - x2, x1 - nl[h]);
			res += (long long)(cur);
		}


	int mup = 1000000, mdw = 1000000;
	for (int i = y1; i <= y2; i ++)
	{
		if (x1 == 0) mup = 0; else
			mup = min(mup, up[x1 - 1][i]);
		if (x2 == n - 1) mdw = 0; else
			mdw = min(mdw, dw[x2 + 1][i]);
	}
	s1 = x1 - mup, s2 = x2 + mdw;
	mn = 1000000;
	for (int i = s1; i <= s2; i ++)
		a[i] = lt[i][y2 + 1] + 1;
	for (int i = x1; i <= x2; i ++)
		mn = min(mn, a[i]);

	l1 = x1 - s1, l2 = s2 - x2;
	levo[0] = pravo[0] = mn;
	for (int i = 1; i <= l1; i ++)
		levo[i] = min(levo[i - 1], lt[x1 - i][y2 + 1] + 1);
	for (int i = 1; i <= l2; i ++)
		pravo[i] = min(pravo[i - 1], lt[x2 + i][y2 + 1] + 1);

	v = 1;
	for (int i = 1; i <= l1; i ++)
	{
		while (v <= l2 && pravo[v] >= levo[i])
			v ++;
		ml[i] = v - 1;
	}
	v = 1;
	for (int i = 1; i <= l2; i ++)
	{
		while (v <= l1 && levo[v] >= pravo[i])
			v ++;
		mr[i] = v - 1;
	}

	sl[0] = sr[0] = mn;
	for (int i = 1; i <= l1; i ++)
		sl[i] = sl[i - 1] + levo[i];
	for (int i = 1; i <= l2; i ++)
		sr[i] = sr[i - 1] + pravo[i];

	//cur = sr[l2] + mn;
	cur = 0;
	for (int i = 0; i <= l1; i ++)
		cur += (ml[i] + 1) * levo[i] + (sr[l2] - sr[ml[i]]);
	res += (long long)(cur);

	return res;
}

void precalc()
{
	for (int i = 0; i < n; i ++)
	{
		lt[i][m - 1] = (s[i][m - 1] == '*' ? 0 : 1);
		for (int j = m - 2; j >= 0; j --)
			if (s[i][j] == '*') lt[i][j] = 0; else lt[i][j] = lt[i][j + 1] + 1;
	}

	for (int j = 0; j < m; j ++)
	{
		up[0][j] = (s[0][j] == '*' ? 0 : 1);
		for (int i = 1; i < n; i ++)
			if (s[i][j] == '*') up[i][j] = 0; else up[i][j] = up[i - 1][j] + 1;
	}

	for (int j = 0; j < m; j ++)
	{
		dw[n - 1][j] = (s[n - 1][j] == '*' ? 0 : 1);
		for (int i = n - 2; i >= 0; i --)
			if (s[i][j] == '*') dw[i][j] = 0; else dw[i][j] = dw[i + 1][j] + 1;
	}
}

int check(int x1, int y1, int x2, int y2)
{
	int res = 0;
	for (int i = 0; i <= x1; i ++)
		for (int j = 0; j <= y1; j ++)
			for (int k = x2; k < n; k ++)
				for (int l = y2; l < m; l ++)
					if (sum(i, j, k, l) == sum(x1, y1, x2, y2)) res ++;
	return res;
}


int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d%d\n", &n, &m, &t);
	for (int i = 0; i < n; i ++)
		gets(s[i]);

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (!used[i][j] && s[i][j] == '*')
			{
				nt ++;
				xl[nt] = yl[nt] = 1000000;
				xr[nt] = yr[nt] = 0;
				dfs(i, j);
				area[nt] = (xr[nt] - xl[nt] + 1) * (yr[nt] - yl[nt] + 1);
			}


	p[0][0] = (s[0][0] == '*' ? 1 : 0);
	for (int i = 1; i < m; i ++)
		p[0][i] = p[0][i - 1] + (s[0][i] == '*' ? 1 : 0);
	for (int i = 1; i < n; i ++)
		p[i][0] = p[i - 1][0] + (s[i][0] == '*' ? 1 : 0);
	for (int i = 1; i < n; i ++)
		for (int j = 1; j < m; j ++)
			p[i][j] = (p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1]) + (s[i][j] == '*' ? 1 : 0);

	t = nt;

	precalc();

	long long res = 0, cur = 0;
	for (int i = 1; i <= t; i ++)
		res += solve(xl[i], yl[i], xr[i], yr[i]);
		//cur += check(xl[i], yl[i], xr[i], yr[i]);
	for (int i = 1; i <= t; i ++)
		for (int j = i + 1; j <= t; j ++)
		{
			int x1 = xl[i], y1 = yl[i], x2 = xr[i], y2 = yr[i];
			x1 = min(x1, xl[j]), y1 = min(y1, yl[j]);
			x2 = max(x2, xr[j]), y2 = max(y2, yr[j]);
			if (sum(x1, y1, x2, y2) == area[i] + area[j])
				res += solve(x1, y1, x2, y2);
				//cur += check(x1, y1, x2, y2);
		}

	for (int i = 1; i <= t; i ++)
		for (int j = i + 1; j <= t; j ++)
			for (int k = j + 1; k <= t; k ++)
			{
				int x1 = xl[i], y1 = yl[i], x2 = xr[i], y2 = yr[i];
				x1 = min(x1, xl[j]), y1 = min(y1, yl[j]);
				x2 = max(x2, xr[j]), y2 = max(y2, yr[j]);
				x1 = min(x1, xl[k]), y1 = min(y1, yl[k]);
				x2 = max(x2, xr[k]), y2 = max(y2, yr[k]);
				if (sum(x1, y1, x2, y2) == area[i] + area[j] + area[k])
					res += solve(x1, y1, x2, y2);
					//cur += check(x1, y1, x2, y2);
			}

	cout << res << endl;
	//cout << cur << endl;
	return 0;
}