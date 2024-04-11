#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	int pos1 = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >> b[i];
		if(b[i] == 1)
			pos1 = i;
	}
	if(pos1 > 0)
	{
		int now = 1, ok = 1;
		for(int i = pos1; i <= n; i ++)
		{
			if(b[i] != now)
			{
				ok = 0;
				break;
			}
			now ++;
		}
		for(int i = 1; i < pos1; i ++)
			if(b[i] > 0 && b[i] - now < i)
			{
				ok = 0;
				break;
			}
		if(ok)
		{
			cout << n - now + 1 << endl;
			return 0;
		}
	}
	int ans = n;
	for(int i = 1; i <= n; i ++)
		if(b[i] > 0)
			ans = max(ans, n + i - b[i] + 1);
	cout << ans << endl;
	
	return 0;
}