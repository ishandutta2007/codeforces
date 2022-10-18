#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>


// http://codeforces.com/contest/467/problem/C

using namespace std;


typedef long long LL;

LL memo[5001][5001];
int n, m, k;
LL sums[5001];

// f(i, j) = max possible if "i" intervals have been done and the next possible interval is j
LL f(int i, int j)
{
	if (i == k || j > n-m)
		return 0;

	LL& r = memo[i][j];

	if (r != -1LL)
		return r;

	return r = max(sums[j]+f(i+1, j+m), f(i, j+1));

}

int main()
{

	cin >> n >> m >> k;

	vector<int> p;
	for (int i = 0; i < n; i++)
	{
		int z;
		cin >> z;
		p.push_back(z);
	}

	memset(memo, -1LL, sizeof(memo));

	for (int i = 0; i < n-m+1; i++)
	{
		sums[i] = 0;
		for (int j = i; j < i+m; j++)
		{
			sums[i] += p[j];
		}
	}

	cout << f(0, 0) << endl;

}