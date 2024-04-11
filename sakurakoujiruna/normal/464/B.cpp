#include <iostream>
#include <numeric>
#include <map>
#include <algorithm>
using namespace std;

typedef long long intl;

int x[8][3];
int p[8][3];

bool found = false;
void check()
{
	map <intl, int> mp;
	for(int i = 0; i < 8; i ++)
		for(int j = i + 1; j < 8; j ++)
		{
			int x1 = x[i][p[i][0]];
			int y1 = x[i][p[i][1]];
			int z1 = x[i][p[i][2]];

			int x2 = x[j][p[j][0]];
			int y2 = x[j][p[j][1]];
			int z2 = x[j][p[j][2]];

			intl dis = (intl)(x1 - x2) * (x1 - x2) +
						(intl)(y1 - y2) * (y1 - y2) +
						(intl)(z1 - z2) * (z1 - z2);
			mp[dis] ++;
		}
	if(mp.size() == 3 && mp.begin() -> second == 12)
	{
		if(!found)
		{
			cout << "YES\n";
			for(int i = 0; i < 8; i ++)
			{
				for(int j = 0; j < 3; j ++)
					cout << x[i][p[i][j]] << ' ';
				cout << '\n';
			}
		}
		found = true;
	}
}

void dfs(int cur)
{
	if(cur == 8)
	{
		check();
		return;
	}
	iota(p[cur], p[cur] + 3, 0);
	do
	{
		dfs(cur + 1);
	}while(next_permutation(p[cur], p[cur] + 3));
}

int main()
{
	ios :: sync_with_stdio(false);
	for(int i = 0; i < 8; i ++)
		for(int j = 0; j < 3; j ++)
			cin >> x[i][j];
	iota(p[0], p[0] + 3, 0);

	dfs(1);
	if(!found)
		cout << "NO\n";
	return 0;
}