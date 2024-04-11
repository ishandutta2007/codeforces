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
const int maxn = 5005;
bool dp[maxn][maxn];
char tmp[maxn];
inline int lowbit(int x)
{
	return x & -x;
}
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	s = "*" + s;
	int limit = (1 << (int)log2(n)) - 1;
	for(int i = 0; i <= limit; i ++)
		dp[0][i] = 1;
	for(int i = 1; i <= n - limit; i ++)
	{
		char mn = 'z' + 1;
		for(int j = 0; j <= limit; j ++)
		{
			tmp[j] = dp[i - 1][j] ? s[i + j] : 'z' + 1;
			mn = min(mn, tmp[j]);
			for(int k = j; k; k -= lowbit(k))
				tmp[j] = min(tmp[j], tmp[j - lowbit(k)]);
		}
		cout << mn;
		for(int j = 0; j <= limit; j ++)
			dp[i][j] = tmp[j] == mn;
	}
	cout << endl;
	
	return 0;
}