#include <iostream>
using namespace std;

const int N = 200011;
typedef long long intl;

intl lt[N];
char ct[N];

intl ls[N];
char cs[N];

int p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
	{
		char c;
		cin >> lt[i] >> c >> ct[i];
		if(i > 0 && ct[i] == ct[i - 1])
		{
			lt[i - 1] += lt[i];
			n --;
			i --;
		}
	}
	for(int i = 0; i < m; i ++)
	{
		char c;
		cin >> ls[i] >> c >> cs[i];
		if(i > 0 && cs[i] == cs[i - 1])
		{
			ls[i - 1] += ls[i];
			m --;
			i --;
		}
	}
	if(n < m)
	{
		cout << 0 << '\n';
		return 0;
	}
	if(m > 2)
	{
		n -= 2;
		m -= 2;
		int last = 0;
		p[1] = 0;
		for(int i = 2; i <= m; i ++)
		{
			while(last > 0 && (cs[i] != cs[last + 1] || ls[i] != ls[last + 1]))
				last = p[last];
			if(cs[i] == cs[last + 1] && ls[i] == ls[last + 1])
				last ++;
			p[i] = last;
		}

		int ans = 0;
		last = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(last == m)
				last = p[last];
			while(last > 0 && (ct[i] != cs[last + 1] || lt[i] != ls[last + 1]))
				last = p[last];
			if(ct[i] == cs[last + 1] && lt[i] == ls[last + 1])
				last ++;
			if(last == m)
			{
				if(cs[m + 1] == ct[i + 1] && ls[m + 1] <= lt[i + 1]
					&& cs[0] == ct[i - m] && ls[0] <= lt[i - m])
					ans ++;
			}
		}
		cout << ans << '\n';
	}
	else if(m == 2)
	{
		int ans = 0;
		for(int i = 0; i < n - 1; i ++)
			if(cs[0] == ct[i] && ls[0] <= lt[i]
				&& cs[1] == ct[i + 1] && ls[1] <= lt[i + 1])
				ans ++;
		cout << ans << '\n';
	}
	else
	{
		intl ans = 0;
		for(int i = 0; i < n; i ++)
		{
			if(cs[0] == ct[i] && ls[0] <= lt[i])
				ans += lt[i] - ls[0] + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}