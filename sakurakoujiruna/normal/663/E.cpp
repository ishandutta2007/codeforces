#include <iostream>
using namespace std;

const int N = (1 << 20);
typedef long long intl;
const intl Mod = (intl)1e9 + 7;
const intl Inv2 = (intl)5e8 + 4;

void dwt(long long x[], int l, int r)
{
	if(l + 1 == r)
		return;
	int mid = (l + r) >> 1;
	dwt(x, l, mid);
	dwt(x, mid, r);
	for(int i = l; i < mid; i ++)
	{
		long long x1 = x[i] - x[i - l + mid];
		long long x2 = x[i] + x[i - l + mid];
		x[i] = (x1 + Mod) % Mod;
		x[i - l + mid] = (x2 + Mod) % Mod;
	}
}

void rdwt(long long x[], int l, int r)
{
	if(l + 1 == r)
		return;
	int mid = (l + r) >> 1;
	for(int i = l; i < mid; i ++)
	{
		long long x1 = x[i];
		long long x2 = x[i - l + mid];
		x[i] = (x1 + x2) * Inv2 % Mod;
		x[i - l + mid] = (x2 - x1) * Inv2 % Mod;
	}
	rdwt(x, l, mid);
	rdwt(x, mid, r);
}

intl a[N], b[N], c[N];
void multi(intl a[], intl b[], intl c[], int n)
{
	dwt(a, 0, n);
	dwt(b, 0, n);
	for(int i = 0; i < n; i ++)
		c[i] = a[i] * b[i] % Mod;
	rdwt(c, 0, n);
	for(int i = 0; i < n; i ++)
	{
		c[i] = (c[i] + Mod) % Mod;
	}
}

int x[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < (1 << n); i ++)
	{
		int t = __builtin_popcount(i);
		b[i] = min(t, n - t);
	}
	for(int i = 0; i < n; i ++)
	{
		string s;
		cin >> s;
		for(int j = 0; j < m; j ++)
			if(s[j] == '1')
				x[j] |= (1 << i);
	}
	for(int i = 0; i < m; i ++)
		a[x[i]] ++;
	multi(a, b, c, (1 << n));
	int ans = ~0U>>1;
	for(int i = 0; i < (1 << n); i ++)
		ans = min((intl)ans, c[i]);
	cout << ans << '\n';
	return 0;
}