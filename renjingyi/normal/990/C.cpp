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
const int maxn = 3e5 + 5;
string s[maxn];
int cnt[maxn];
int appear[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> s[i];
	for(int i = 1; i <= n; i ++)
	{
		int s0 = 0, s1 = 0;
		bool ok = 1;
		for(int j = 0; j < s[i].size(); j ++)
		{
			if(s[i][j] == '(')
				s0 ++;
			else
				s1 ++;
			if(s0 < s1)
			{
				ok = 0;
				break;
			}
		}
		if(!ok)
			cnt[i] = -1;
		else
			cnt[i] = s0 - s1;
		s0 = s1 = 0;
		ok = 1;
		for(int j = (int)s[i].size() - 1; j >= 0; j --)
		{
			if(s[i][j] == '(')
				s0 ++;
			else
				s1 ++;
			if(s1 < s0)
			{
				ok = 0;
				break;
			}
		}
		if(ok)
			appear[s1 - s0] ++;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i ++)
		if(cnt[i] >= 0)
			ans += appear[cnt[i]];
	cout << ans << endl;
	
	return 0;
}