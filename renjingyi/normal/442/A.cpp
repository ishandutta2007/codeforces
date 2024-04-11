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
int a[maxn], b[maxn];
map<char, int> id;
bool connect[maxn][maxn];
bool mark1[maxn], mark2[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	id['R'] = 0;
	id['G'] = 1;
	id['B'] = 2;
	id['Y'] = 3;
	id['W'] = 4;
	for(int i = 1; i <= n; i ++)
	{
		char c1, c2;
		cin >> c1 >> c2;
		a[i] = id[c1];
		b[i] = c2 - '0' - 1;
		connect[a[i]][b[i]] = 1;
	}
	int ans = maxn;
	for(int i = 0; i < (1 << 5); i ++)
		for(int j = 0; j < (1 << 5); j ++)
		{
			for(int k = 0; k < 5; k ++)
			{
				mark1[k] = (i >> k) & 1;
				mark2[k] = (j >> k) & 1;
			}
			bool ok = 1;
			for(int p = 1; p <= n; p ++)
			{
				if(mark1[a[p]] && mark2[b[p]])
					continue;
				else if(mark1[a[p]])
				{
					int cnt = 0;
					for(int k = 0; k < 5; k ++)
						if(connect[a[p]][k] && !mark2[k])
							cnt ++;
					if(cnt > 1)
						ok = 0;
				}
				else if(mark2[b[p]])
				{
					int cnt = 0;
					for(int k = 0; k < 5; k ++)
						if(connect[k][b[p]] && !mark1[k])
							cnt ++;
					if(cnt > 1)
						ok = 0;
				}
				else
				{
					int cnt = 0;
					for(int k = 0; k < 5; k ++)
						for(int l = 0; l < 5; l ++)
							if(connect[k][l] && !mark1[k] && !mark2[l])
								cnt ++;
					if(cnt > 1)
						ok = 0;
				}
			}
			if(ok)
			{
				int cnt = 0;
				for(int k = 0; k < 5; k ++)
					cnt += ((i >> k) & 1) + ((j >> k) & 1);
				ans = min(ans, cnt);
			}
		}
	cout << ans << endl;
	
	return 0;
}