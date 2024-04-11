#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int N = 1000011 * 2;
typedef long long intl;
const intl Mod = (intl)1e9 + 7;

string s;
int cnt[N];
intl dp[N];

stack <int> sta[26];

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	cin >> s;
	int m = s.size();
	int all = 0;
	for(int i = 0; i < s.size(); i ++)
	{
		cnt[s[i] - 'a'] ++;
		if(cnt[s[i] - 'a'] == 1)
			all ++;
	}
	int last = 0;
	for(int i = 0; i < n; i ++)
	{
		while(all == k)
		{
			if(cnt[s[last] - 'a'] == 1)
				all --;
			cnt[s[last] - 'a'] --;
			last ++;
		}
		for(int j = 0; j < k; j ++)
			if(cnt[j] == 0)
			{
				cnt[j] ++;
				s += (char)(j + 'a');
				all ++;
				break;
			}
	}
	//cout << s << '\n';
	n = s.size();
	for(int i = n - 1; i >= 0; i --)
		sta[s[i] - 'a'].push(i + 1);

	dp[0] = 1;
	intl ans = 0;
	for(int i = 0; i <= n; i ++)
	{
		for(int j = 0; j < k; j ++)
		{
			while(sta[j].size() && sta[j].top() <= i)
				sta[j].pop();
			if(sta[j].size())
			{
				dp[sta[j].top()] += dp[i];
				dp[sta[j].top()] %= Mod;
			}
		}
		//cout << i << ' ' << dp[i] << '\n';
		ans += dp[i];
		ans %= Mod;
	}
	cout << ans << '\n';
	return 0;
}