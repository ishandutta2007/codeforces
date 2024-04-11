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
typedef pair<long long, long long> pp;
const int maxm = 1e5 + 5;
long long a[maxm];
pp b[maxm];
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= m; i ++)
		{
			cin >> a[i] >> b[i].first;
			b[i].second = a[i];
		}
		sort(a + 1, a + m + 1);
		sort(b + 1, b + m + 1);
		int pos = m, cnt = 0;
		long long now = 0, ans = 0;
		for(int i = m; i >= 1; i --)
		{
			for(; pos && a[pos] > b[i].first; pos --)
				if(cnt < n)
				{
					now += a[pos];
					cnt ++;
				}
			if(cnt < n)
				ans = max(ans, b[i].second > b[i].first ? now + (n - cnt) * b[i].first : now + b[i].second + (n - cnt - 1) * b[i].first);
			else
				ans = max(ans, now);
		}
		cout << ans << endl;
	}
	
	return 0;
}