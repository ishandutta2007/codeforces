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
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<int, int> pp;
const int maxn = 1005;
pp x[maxn];
bool cmp(const pp &a, const pp &b)
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		x[i] = mp(a + b + c + d, i);
	}
	sort(x + 1, x + n + 1, cmp);
	for(int i = 1; i <= n; i ++)
		if(x[i].second == 1)
			cout << i << endl;
	
	return 0;
}