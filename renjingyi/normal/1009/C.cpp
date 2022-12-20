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
const int maxn = 1e5 + 5;
long long x[maxn], d[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	long long n, m;
	cin >> n >> m;
	long long tot = 0;
	int pos = n / 2 + 1;
	long long cnt = 0;
	for(int i = 1; i <= n; i ++)
		cnt += abs(i - pos);
	for(int i = 1; i <= m; i ++)
	{
		cin >> x[i] >> d[i];
		tot += x[i] * n;
		if(d[i] >= 0)
			tot += n * (n - 1) / 2 * d[i];
		else
			tot += cnt * d[i];
	}
	cout << fixed << setprecision(7) << (double)tot / n << endl;
	
	return 0;
}