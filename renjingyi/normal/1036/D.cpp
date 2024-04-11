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
long long a[maxn], b[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long sa = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		sa += a[i];
	}
	int m;
	cin >> m;
	long long sb = 0;
	for(int i = 1; i <= m; i ++)
	{
		cin >> b[i];
		sb += b[i];
	}
	if(sa != sb)
	{
		cout << -1 << endl;
		return 0;
	}
	sa = sb = 0;
	int pos1 = 1, pos2 = 1;
	int cnt = 0;
	while(pos1 <= n || pos2 <= m)
	{
		if(sa <= sb)
			sa += a[pos1 ++];
		else
			sb += b[pos2 ++];
		if(sa == sb)
		{
			sa = sb = 0;
			cnt ++;
		}
	}
	cout << cnt << endl;
	
	return 0;
}