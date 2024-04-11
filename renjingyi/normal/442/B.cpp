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
#include <iomanip>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 105;
double p[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> p[i];
	sort(p + 1, p + n + 1);
	reverse(p + 1, p + n + 1);
	double a = 1, b = 0, c = 0;
	for(int i = 1; i <= n; i ++)
		if(a > b)
		{
			c = c + b * p[i];
			b = b * (1 - p[i]) + a * p[i];
			a = a * (1 - p[i]);
		}
	cout << fixed << setprecision(10) << b << endl;
	
	return 0;
}