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
const long long oo = 1e18;
long long a[maxn], b[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	long long n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= m; i ++)
		cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	long long ans = 0;
	if(k >= n)
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i <= k; i ++)
	{
		int pos = lower_bound(b + 1, b + m + 1, a[i + 1] + ta) - b;
		if(pos + k - i > m || a[i + 1] + ta > b[pos + k - i])
		{
			cout << -1 << endl;
			return 0;
		}
		ans = max(ans, b[pos + k - i] + tb);
	}
	cout << ans << endl;
	
	return 0;
}