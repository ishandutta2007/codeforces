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
const int maxn = 3e5 + 5;
int p[maxn], pos[maxn];
vector<pp> ans;
void gao(const int &a, const int &b)
{
	ans.push_back(mp(a, b));
	swap(pos[p[a]], pos[p[b]]);
	swap(p[a], p[b]);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> p[i];
		pos[p[i]] = i;
	}
	for(int i = 1; i <= n; i ++)
	{
		if(pos[i] == i)
			continue;
		int a = i, b = pos[i];
		if(abs(a - b) >= n / 2)
			gao(a, b);
		else if(a > n / 2 && b > n / 2)
		{
			gao(a, 1);
			gao(1, b);
			gao(a, 1);
		}
		else if(a <= n / 2 && b <= n / 2)
		{
			gao(a, n);
			gao(n, b);
			gao(a, n);
		}
		else
		{
			if(a > b)
				swap(a, b);
			gao(a, n);
			gao(b, 1);
			gao(1, n);
			gao(a, n);
			gao(b, 1);
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i ++)
	{
		int a = ans[i].first, b = ans[i].second;
		cout << a << " " << b << endl;
	}
	
	return 0;
}