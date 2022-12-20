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
bool mark[maxn];
int qq[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	string s, t;
	cin >> s >> t;
	for(int i = 0; i < (int)s.size() - (int)t.size() + 1; i ++)
	{
		mark[i] = 1;
		for(int j = i; j < i + t.size(); j ++)
			if(s[j] != t[j - i])
			{
				mark[i] = 0;
				break;
			}
		qq[i + 1] = qq[i] + mark[i];
	}
	for(int i = 1; i <= q; i ++)
	{
		int l, r;
		cin >> l >> r;
		if(r - l + 1 >= t.size())
			cout << qq[r - (int)t.size() + 1] - qq[l - 1] << endl;
		else
			cout << 0 << endl;
	}
	
	return 0;
}