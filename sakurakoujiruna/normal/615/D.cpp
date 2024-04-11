#include <iostream>
#include <map>
using namespace std;

typedef long long intl;
const intl Mod = (intl)1e9 + 7;

intl qpow(intl a, intl b)
{
	intl ret = 1;
	intl tmp = a;
	while(b > 0)
	{
		if(b & 1)
		{
			ret *= tmp;
			ret %= Mod;
		}
		tmp *= tmp;
		tmp %= Mod;
		b >>= 1;
	}
	return ret;
}

const int N = 211111;
intl a[N];
intl b[N];
intl pre[N];
intl suf[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	map <int, int> mp;
	for(int i = 0; i < n; i ++)
	{
		int x;
		cin >> x;
		mp[x] ++;
	}
	int cnt = 0;
	intl ttt = 1;
	for(auto it = mp.begin(); it != mp.end(); it ++)
	{
		cnt ++;
		a[cnt] = it -> first;
		b[cnt] = it -> second;
		ttt = ttt * (b[cnt] + 1) % Mod;
	}
	pre[0] = suf[cnt + 1] = 1;
	for(int i = 1; i <= cnt; i ++)
		pre[i] = pre[i - 1] * (b[i] + 1) % (Mod - 1);
	for(int i = cnt; i >= 1; i --)
		suf[i] = suf[i + 1] * (b[i] + 1) % (Mod - 1);
	intl ans = 1;
	
	for(int i = 1; i <= cnt; i ++)
	{
		//int a = it -> first;
		//int b = it -> second;
		intl tmp = qpow(a[i], (intl)b[i] * (b[i] + 1) / 2);
		//cout << tmp << '\n';
		tmp = qpow(tmp, pre[i - 1] * suf[i + 1] % (Mod - 1));
		//cout << tmp << '\n';
		ans = ans * tmp % Mod;
	}
	cout << ans << '\n';
	return 0;
}