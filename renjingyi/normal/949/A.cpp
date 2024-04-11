#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> ans[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < s.size(); i ++)
	{
		if(s[i] == '0')
			cnt0 ++;
		else
			cnt1 ++;
	}
	if(cnt0 <= cnt1)
	{
		cout << -1 << endl;
		return 0;
	}
	int now = 0, real = 0;
	bool changed = 0;
	for(int i = 0; i < s.size(); i ++)
	{
		if(s[i] == '0')
		{
			if(now < cnt0 - cnt1 && !changed)
			{
				now ++;
				if(now == cnt0 - cnt1)
					changed = 1;
				ans[now].push_back(i);
			}
			else
			{
				if(real > 0)
				{
					ans[real].push_back(i);
					real --;
				}
				else
				{
					cout << -1 << endl;
					return 0;
				}
			}
		}
		else
		{
			real ++;
			ans[real].push_back(i);
			if(real > now)
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << cnt0 - cnt1 << endl;
	for(int i = 1; i <= cnt0 - cnt1; i ++)
	{
		cout << ans[i].size() << " ";
		for(int j = 0; j < ans[i].size(); j ++)
			cout << ans[i][j] + 1 << " ";
		cout << endl;
	}
	
	return 0;
}