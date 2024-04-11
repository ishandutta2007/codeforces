#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int a[600], b[600];
int a1[600], b1[600];
short d[501][501][501];
int n, m;

set < int > S;
map < int, int > MP;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]), S.insert(a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++)
		scanf("%d", &b[i]);

	int z = 0;
	for (set < int > :: iterator it = S.begin(); it != S.end(); it ++)
		z ++, MP[* it] = z;

	for (int i = 1; i <= n; i ++)
		a1[i] = MP[a[i]];
	for (int i = 1; i <= m; i ++)
		if (MP.count(b[i])) b1[i] = MP[b[i]]; else b[i] = 1000;

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			for (int k = 1; k <= z; k ++)
			{
				d[i][j][k] = max(d[i - 1][j][k], d[i][j - 1][k]);
				d[i][j][k] = max(d[i][j][k], d[i][j][k - 1]);
				if (a1[i] == b1[j] && a1[i] <= k)
					d[i][j][k] = max(d[i][j][k], (short)(d[i - 1][j - 1][a1[i] - 1] + 1));
			}

	printf("%d\n", d[n][m][z]);
	int x = n, y = m, p = z;
	vector < int > res;
	while (true)
	{
		if (d[x][y][p] == 0) break;
		if (d[x][y][p] == d[x - 1][y][p]) x --; else
			if (d[x][y][p] == d[x][y - 1][p]) y --; else 
				if (d[x][y][p] == d[x][y][p - 1]) p --; else 
					res.push_back(a[x]), p = a1[x] - 1, x --, y --;
	}

	reverse(res.begin(), res.end());
	for (int i = 0; i < res.size(); i ++)
		printf("%d ", res[i]);
	printf("\n");

	return 0;
}