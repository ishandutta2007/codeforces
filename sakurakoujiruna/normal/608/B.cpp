#include <iostream>
using namespace std;

const int N = 201111;
typedef long long intl;

int pre[N];

int main()
{
	ios :: sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();
	pre[0] = 0;
	for(int i = 1; i <= m; i ++)
	{
		pre[i] = pre[i - 1];
		if(b[i - 1] == '1')
			pre[i] ++;
	}
	intl ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		int c1 = pre[i + m - n] - pre[i - 1];
		int c0 = m - n + 1 - c1;
		//cout << c0 << ' ' << c1 << '\n';
		if(a[i - 1] == '0')
			ans += c1;
		else
			ans += c0;
	}
	cout << ans << '\n';
	return 0;
}