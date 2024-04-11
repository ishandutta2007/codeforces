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
int n, m;
inline int work(int a, int x, int y)
{
	return (x * y - a * x + 2 * a * y - 2 * y * y - 1) / (x + y) - m;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	long long ans = 0;
	int a = n + 1;
	int asd = n - m - m;
	for(int j = m + 1; j <= n / 2 && n - j >= m; j ++)
		for(int i = m + 1; i <= n && n - i >= m; i ++)
		{
			int now = work(a, i, j);
			if(now <= 0)
				break;
			ans += min(now, asd);
		}
	ans <<= 1;
	if(n & 1)
		for(int i = m + 1; i <= n && n - i >= m; i ++)
		{
			int now = work(a, i, n / 2 + 1);
			if(now <= 0)
				break;
			ans += min(now, asd);
		}
	cout << ans * 3 << endl;
	
	return 0;
}