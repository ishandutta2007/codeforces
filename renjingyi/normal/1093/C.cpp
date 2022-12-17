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
long long b[maxn];
long long a[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	a[n + 1] = 1e18 + 1;
	for(int i = 1; i <= n / 2; i ++)
	{
		cin >> b[i];
		if(b[i] - a[i - 1] <= a[n - i + 2])
		{
			a[i] = a[i - 1];
			a[n - i + 1] = b[i] - a[i];
		}
		else
		{
			a[n - i + 1] = a[n - i + 2];
			a[i] = b[i] - a[n - i + 1];
		}
	}
	for(int i = 1; i <= n; i ++)
		cout << a[i] << " ";
	cout << endl;
	
	return 0;
}