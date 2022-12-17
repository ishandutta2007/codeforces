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
int du[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;
	for(int i = 1; i < n; i ++)
	{
		int a, b;
		cin >> a >> b;
		du[a] ++;
		du[b] ++;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++)
		cnt += du[i] == 1;
	cout << fixed << setprecision(9) << 2.0 * s / cnt << endl;
	
	return 0;
}