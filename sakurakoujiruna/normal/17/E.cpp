#include <iostream>
using namespace std;

const int N = 4111111;
typedef long long intl;
const intl Mod = 51123987;
const intl Inv2 = (Mod + 1) / 2;

int r[N];
void manacher(int n, string s, int r[]) // $#a#b#a#@
{
	static char c[N];
	for(int i = 0; i < n; i ++)
	{
		c[2 * i + 1] = '#';
		c[2 * i + 2] = s[i];
	}
	c[2 * n + 1] = '#';
	c[0] = '$';
	c[2 * n + 2] = '@';
	int p = 0, mx = 0;
	for(int i = 0; i < 2 * n + 3; i ++)
	{
		if(mx > i)
			r[i] = min(mx - i, r[2 * p - i]);
		else
			r[i] = 1;
		while(c[i + r[i]] == c[i - r[i]])
			r[i] ++;
		if(i + r[i] > mx)
		{
			mx = i + r[i];
			p = i;
		}
	}
}

intl st[N], ed[N];
void add(int l, int r)
{
	int l1 = l;
	int r1 = r - (r - l + 1) / 2;
	int l2 = l + (r - l + 1) / 2;
	int r2 = r;
	st[l1] ++;
	st[r1 + 1] --;
	ed[l2] ++;
	ed[r2 + 1] --;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	manacher(n, s, r);
	for(int i = 1; i <= n; i ++)
		add(i - r[i * 2] / 2 + 1, i + r[i * 2] / 2 - 1);
	for(int i = 1; i < n; i ++)
		if(r[i * 2 + 1] > 1)
			add(i - r[i * 2 + 1] / 2 + 1, i + r[i * 2 + 1] / 2);
	
	for(int i = 1; i <= n; i ++)
	{
		st[i] += st[i - 1];
		ed[i] += ed[i - 1];
		st[i] %= Mod;
		ed[i] %= Mod;
	}
	for(int i = 1; i <= n; i ++)
	{
		ed[i] += ed[i - 1];
		ed[i] %= Mod;
	}
	intl ans = ed[n] * (ed[n] - 1) % Mod * Inv2 % Mod;
	for(int i = 1; i <= n; i ++)
	{
		ans -= st[i] * ed[i - 1];
		ans %= Mod;
	}
	cout << (ans + Mod) % Mod << '\n';
	return 0;
}