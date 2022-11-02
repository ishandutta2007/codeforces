#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long intl;
const int N = 501111;
const intl Mod = (intl)1e9 + 7;
const intl Inf = 0x3f3f3f3f3f3f3f3fLL;

int dx[N];
int dy[N];

intl sx[N];
intl sy[N];

bool solve(int n, int m, int c[], intl s[])
{
	for(int i = 0; i < m; i ++)
		s[i] = Inf;
	int acc = 0;
	for(int i = 0; i < n; i ++)
	{
		acc += c[i];
		if(acc > 0 && acc <= m)
			s[m - acc] = min(s[m - acc], (intl)i + 1);
		if(acc < 0 && -acc <= m)
			s[-acc - 1] = min(s[-acc - 1], (intl)i + 1);
	}
	if(acc > 0)
		for(int i = m - acc - 1; i >= 0; i --)
			s[i] = min(s[i], s[i + acc] + n);
	else if(acc < 0)
	{
		acc = -acc;
		for(int i = acc; i < m; i ++)
			s[i] = min(s[i], s[i - acc] + n);
	}
	/*
	for(int i = 0; i < m; i ++)
		cout << s[i] << ' ';
	cout << '\n';
	*/
	for(int i = 0; i < m; i ++)
		if(s[i] == Inf)
			return false;
	return true;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, h, w;
	cin >> n >> h >> w;
	string str;
	cin >> str;
	for(int i = 0; i < n; i ++)
		if(str[i] == 'U')
			dx[i] = -1;
		else if(str[i] == 'D')
			dx[i] = 1;
		else if(str[i] == 'L')
			dy[i] = -1;
		else
			dy[i] = 1;
	bool s1 = solve(n, h, dx, sx);
	bool s2 = solve(n, w, dy, sy);
	if(!s1 && !s2)
		cout << -1 << '\n';
	else
	{
		sort(sx, sx + h);
		sort(sy, sy + w);
		int p = 0;
		intl ans = 0;
		intl sum = 0;
		for(int i = 0; i < h; i ++)
		{
			while(p < w && sy[p] <= sx[i])
			{
				sum += sy[p];
				sum %= Mod;
				p ++;
			}
			ans += sum;
			ans %= Mod;
			ans += sx[i] % Mod * (w - p) % Mod;
			ans %= Mod;
		}
		cout << ans << '\n';
	}
	return 0;
}