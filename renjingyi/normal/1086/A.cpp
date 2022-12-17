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
int x[3], y[3];
int a[3], b[3];
vector<pp> ans;
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
	for(int i = 0; i < 3; i ++)
	{
		a[i] = x[i];
		b[i] = y[i];
	}
	sort(x, x + 3);
	sort(y, y + 3);
	for(int i = x[0]; i <= x[2]; i ++)
		ans.push_back(mp(i, y[1]));
	for(int i = 0; i < 3; i ++)
		if(b[i] == y[0])
		{
			for(int j = b[i]; j < y[1]; j ++)
				ans.push_back(mp(a[i], j));
			break;
		}
	for(int i = 0; i < 3; i ++)
		if(b[i] == y[2])
		{
			for(int j = b[i]; j > y[1]; j --)
				ans.push_back(mp(a[i], j));
			break;
		}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i ++)
		cout << ans[i].first << " " << ans[i].second << endl;
	
	return 0;
}