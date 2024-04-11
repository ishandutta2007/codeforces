#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 101111;
pair <int, int> p[N];
int dp[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> p[i].first >> p[i].second;
	sort(p, p + n);
	int ans = 0x3f3f3f3f;
	dp[0] = 0;
	for(int i = 1; i < n; i ++)
	{
		if(p[i].first - p[i].second > p[i - 1].first)
			dp[i] = dp[i - 1];
		else if(p[i].first - p[i].second <= p[0].first)
			dp[i] = i;
		else
		{
			int left = 0, right = i;
			while(left + 1 < right)
			{
				int mid = (left + right) >> 1;
				if(p[i].first - p[i].second > p[mid].first)
					left = mid;
				else
					right = mid;
			}
			dp[i] = dp[left] + (i - left - 1);
		}
	}
	for(int i = 0; i < n; i ++)
		ans = min(ans, dp[i] + (n - i - 1));
	cout << ans << '\n';
	return 0;
}