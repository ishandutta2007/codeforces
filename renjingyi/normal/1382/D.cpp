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
const int maxn = 2005;
bool mark[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		int n;
		cin >> n;
		int pos = 1;
		vector<int> block;
		int last = 0;
		for(int i = 1; i <= n + n; i ++)
		{
			int p;
			cin >> p;
			if(i == 1)
				last = p;
			else if(p > last)
			{
				block.push_back(i - pos);
				pos = i;
				last = p;
			}
		}
		block.push_back(n + n + 1 - pos);
		for(int i = 0; i <= n; i ++)
			for(int j = 0; j <= n; j ++)
				mark[i][j] = 0;
		queue<pp> q;
		int sum = 0;
		q.push(mp(0, 0));
		for(int i = 0; i < block.size(); i ++)
		{
			int now = block[i];
			while(!q.empty())
			{
				int a = q.front().first, b = q.front().second;
				if(a + b != sum)
					break;
				q.pop();
				if(mark[a][b])
					continue;
				mark[a][b] = 1;
				if(a + now <= n)
					q.push(mp(a + now, b));
				if(b + now <= n)
					q.push(mp(a, b + now));
			}
			sum += now;
		}
		cout << (q.empty() ? "NO" : "YES") << endl;
	}
	
	return 0;
}