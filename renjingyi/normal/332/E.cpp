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
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef unsigned long long u64;
typedef pair<u64, u64> pp;
const u64 base1 = 1e9 + 7, base2 = 2333;
const int maxk = 2005, maxs = 2005;
pp codep[maxk], codes[maxs];
pp hashh(const string &s, const int &p, const int &k)
{
	pp code(0, 0), now(1, 1);
	for(int i = p; i < s.size(); i += k)
	{
		code.first += s[i] * now.first;
		code.second += s[i] * now.second;
		now.first *= base1;
		now.second *= base2;
	}
	return code;
}
bool dp[maxk][maxs];
int main()
{
	std::ios::sync_with_stdio(false);
	string p, s;
	getline(cin, p);
	getline(cin, s);
	int k;
	cin >> k;
	if(p.size() / k > s.size())
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1; i <= k; i ++)
		codep[i] = hashh(p, i - 1, k);
	int d = p.size() / k, r = p.size() % k;
	for(int i = 1; i <= k + 1; i ++)
		dp[i][0] = 1;
	bool mark = 0;
	string ans = "0";
	for(int a = 0; a <= r; a ++)
		for(int b = 0; b <= (d ? k - r : 0); b ++)
			if(a * (d + 1) + b * d == s.size())
			{
				int n = a + b;
				for(int i = 1; i <= n; i ++)
					codes[i] = hashh(s, i - 1, n);
				for(int i = k; i >= 1; i --)
					for(int j = 1; j <= n; j ++)
					{
						if(codep[i].first == codes[n - j + 1].first && codep[i].second == codes[n - j + 1].second)
							dp[i][j] = dp[i + 1][j - 1] | dp[i + 1][j];
						else
							dp[i][j] = dp[i + 1][j];
						
					}
				if(dp[1][n])
				{
					string now = "";
					int cnt = n;
					for(int i = 2; i <= k; i ++)
					{
						if(!dp[i][cnt])
						{
							now += '1';
							cnt --;
						}
						else
							now += '0';
					}
					now += cnt ? '1' : '0';
					if(!mark)
					{
						mark = 1;
						ans = now;
					}
					else
						ans = min(ans, now);
				}
			}
	cout << ans << endl;
	
	return 0;
}