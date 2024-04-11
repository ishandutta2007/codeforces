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
typedef pair<int, int> pp;
const int maxn = 5e5 + 5;
int a[maxn];
int from[maxn], to[maxn];
pp b[maxn];
bool mark[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		b[i].first = a[i];
		b[i].second = i;
	}
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i ++)
	{
		from[i] = i - 1;
		to[i] = i + 1;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		int x = b[i].first, y = b[i].second;
		if(a[from[y]] < x || a[to[y]] < x)
			continue;
		ans += min(a[from[y]], a[to[y]]);
		to[from[y]] = to[y];
		from[to[y]] = from[y];
		mark[y] = 1;
	}
	mark[1] = mark[n] = 1;
	int mx = 0, mxpos = 0;
	for(int i = 1; i <= n; i ++)
		if(!mark[i])
		{
			int now = min(a[from[i]], a[to[i]]);
			if(now > mx)
			{
				mx = now;
				mxpos = i;
			}
		}
	while(mxpos > 1 && mxpos < n)
	{
		ans += min(a[from[mxpos]], a[to[mxpos]]);
		int x = from[mxpos], y = to[mxpos];
		to[x] = y;
		from[y] = x;
		mxpos = min(a[from[x]], a[to[x]]) > min(a[from[y]], a[to[y]]) ? x : y;
	}
	cout << ans << endl;
	
	return 0;
}