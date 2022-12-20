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
const int maxn = 35;
bool correct[35];
int main()
{
	std::ios::sync_with_stdio(false);
	int m, n;
	cin >> m >> n;
	for(int i = 1; i <= n; i ++)
	{
		cout << 1 << endl;
		cout.flush();
		int ans;
		cin >> ans;
		if(!ans)
			return 0;
		correct[i] = ans == 1;
	}
	int l = 1, r = m;
	int cnt = 0;
	while(l < r)
	{
		int mid = (l + r) >> 1;
		cout << mid << endl;
		cout.flush();
		int ans;
		cin >> ans;
		if(!ans)
			return 0;
		cnt %= n;
		cnt ++;
		if(!correct[cnt])
			ans *= -1;
		if(ans < 0)
			r = mid - 1;
		else
			l = mid + 1;
	}
	cout << l << endl;
	cout.flush();
	
	return 0;
}