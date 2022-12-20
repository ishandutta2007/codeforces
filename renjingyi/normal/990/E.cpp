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
const int maxn = 1e6 + 5;
long long a[maxn];
bool mark[maxn];
int f[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++)
	{
		int x;
		cin >> x;
		mark[x] = 1;
	}
	for(int i = 1; i <= k; i ++)
		cin >> a[i];
	if(mark[0])
	{
		cout << -1 << endl;
		return 0;
	}
	int mx = 0, tmp = 0, now = 0;
	for(int i = 0; i < n; i ++)
	{
		if(mark[i])
		{
			f[i] = tmp;
			now ++;
		}
		else
		{
			mx = max(mx, now);
			f[i] = tmp = i;
			now = 0;
		}
	}
	mx = max(mx, now);
	if(k - 1 < mx)
	{
		cout << -1 << endl;
		return 0;
	}
	long long ans = 1e16;
	for(int i = mx + 1; i <= k; i ++)
	{
		int cnt = 0, pos = 0;
		bool ok = 0;
		while(pos < n)
		{
			cnt ++;
			pos += i;
			if(pos < n)
				pos = f[pos];
		}
		ans = min(ans, a[i] * cnt);
	}
	cout << ans << endl;
	
	return 0;
}