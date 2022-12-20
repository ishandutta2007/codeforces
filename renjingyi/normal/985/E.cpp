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
const int maxn = 5e5 + 5;
int a[maxn];
bool mark[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k, d;
	cin >> n >> k >> d;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	mark[0] = 1;
	int tmp = 0;
	int last = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(!mark[tmp])
			tmp ++;
		if(i - tmp >= k)
		{
			last = tmp;
			for(tmp ++; tmp < i && !mark[tmp]; tmp ++);
		}
		if(i - last >= k && abs(a[i] - a[last + 1]) <= d)
			mark[i] = 1;
	}
	cout << (mark[n] ? "YES" : "NO") << endl;
	
	return 0;
}