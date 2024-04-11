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

#include <string.h>

using namespace std;


typedef unsigned long long LL;

typedef pair<LL,LL> pLL;

int knows[4001][4001];

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n+1);
	map<int,int> rec;
	set<int> x;
	memset(knows, 0, sizeof(knows));
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		x.insert(a);
		x.insert(b);
		v[a].push_back(b);
		v[b].push_back(a);
		rec[a]++;
		rec[b]++;
		knows[a][b] = knows[b][a] = 1;
	}
	int best = -1;
	for (auto a : x)
	{
		int na = v[a].size();
		for (int j = 0; j < na; j++)
		{
			int b = v[a][j];
			for (int k = j+1; k < na; k++)
			{
				int c = v[a][k];
				//cout << a << " " << b << " " << c << endl;
				//cout << knows[a][b] << " " << knows[a][c] << " " << knows[b][c] << endl;
				if (!knows[b][c]) continue;
				int s = rec[a]+rec[b]+rec[c]-6;
				if (best == -1 || s < best)
					best = s;
			}
		}
	}
	cout << best << endl;
	exit(0);
}