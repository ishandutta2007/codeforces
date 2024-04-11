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
const int maxn = 105;
int a[maxn], b[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int x = 0, y = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		x ^= a[i];
	}
	for(int i = 1; i <= m; i ++)
	{
		cin >> b[i];
		y ^= b[i];
	}
	if(x != y)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i = 1; i < n; i ++)
	{
		for(int j = 1; j < m; j ++)
			cout << 0 << " ";
		cout << a[i] << endl;
	}
	for(int i = 1; i < m; i ++)
		cout << b[i] << " ";
	int asd = a[n];
	for(int i = 1; i < m; i ++)
		asd ^= b[i];
	cout << asd << endl;
	
	return 0;
}