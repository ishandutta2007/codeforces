#include <iostream>
#include <vector>
using namespace std;

const int N = 100011;

vector <int> v[N];
void factor(int x, vector <int> &v)
{
	for(int i = 2; i * i <= x; i ++)
		if(x % i == 0)
		{
			v.push_back(i);
			while(x % i == 0)
				x /= i;
		}
	if(x != 1)
		v.push_back(x);
}

int dp[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	if(n == 1)
	{
		cout << 1 << '\n';
		return 0;
	}
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		factor(x, v[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		int now = 0;
		for(auto &x : v[i])
			now = max(now, dp[x]);
		now ++;
		ans = max(ans, now);
		for(auto &x : v[i])
			dp[x] = max(dp[x], now);
	}
	cout << ans << '\n';
	return 0;
}