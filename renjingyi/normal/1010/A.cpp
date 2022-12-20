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
#include <iomanip>
using namespace std;
const int maxn = 1005;
int a[maxn], b[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		cin >> b[i];
	b[n + 1] = b[1];
	double tot = m;
	for(int i = n + 1; i >= 2; i --)
	{
		if(b[i] == 1)
		{
			cout << -1 << endl;
			return 0;
		}
		tot += tot / (b[i] - 1);
		if(a[i - 1] == 1)
		{
			cout << -1 << endl;
			return 0;
		}
		tot += tot / (a[i - 1] - 1);
	}
	cout << fixed << setprecision(7) << tot - m << endl;
	
	return 0;
}