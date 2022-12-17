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
const int maxn = 1005;
bool a[maxn], b[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		int n, m;
		cin >> n >> m;
		int x;
		for(int i = 1; i <= 1000; i ++)
			a[i] = b[i] = 0;
		for(int i = 1; i <= n; i ++)
		{
			cin >> x;
			a[x] = 1;
		}
		for(int i = 1; i <= m; i ++)
		{
			cin >> x;
			b[x] = 1;
		}
		bool get = 0;
		for(int i = 1; i <= 1000; i ++)
			if(a[i] && b[i])
			{
				cout << "YES" << endl;
				cout << 1 << " " << i << endl;
				get = 1;
				break;
			}
		if(!get)
			cout << "NO" << endl;
	}
	
	return 0;
}