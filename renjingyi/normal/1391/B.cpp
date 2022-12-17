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
char c[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				cin >> c[i][j];
		int ans = 0;
		for(int i = 1; i < n; i ++)
			ans += c[i][m] == 'R';
		for(int i = 1; i < m; i ++)
			ans += c[n][i] == 'D';
		cout << ans << endl;
	}
	
	return 0;
}