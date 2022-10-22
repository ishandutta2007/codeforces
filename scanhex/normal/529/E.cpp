#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
typedef long long ll;

using namespace std;

int main()
{
	int n, k, q;
	scanf("%d %d", &n, &k);
	++n;
	vector<int> sz(n);
	for (int i = 0; i < n - 1; ++i)
		scanf("%d", &sz[i]);
	sz[n - 1] = 0;
	scanf("%d", &q);
	vector<int> qs(q);
	for (int i = 0; i < q; ++i)
		scanf("%d", &qs[i]);
	vector<vector<int>> sums(k + 1);
	for (int i = 0; i <= k; ++i)
	{
		sums[i] = vector<int>(n);
		for (int j = 0; j < n; ++j)
		{
			sums[i][j] = sz[j] * i;
		}
		sort(sums[i].begin(), sums[i].end());
	}
	for (int i = 0; i < q; ++i)
	{
		int minx = k + 1;
		for (int sz1 = 0; sz1 <= k; ++sz1)
			for (int sz2 = 0; sz2 <= k; ++sz2)
			{
				int p2 = n - 1;
				for (int p1 = 0; p1 < n; ++p1)
				{
					while (p2 >= 0 && sums[sz1][p1] + sums[sz2][p2] > qs[i])
						--p2;
					if (p2 == -1)
						break;
					if (sums[sz1][p1] + sums[sz2][p2] == qs[i])
						minx = min(minx, sz1 + sz2);
				}
			}
		printf("%d\n", minx == k + 1 ? -1 : minx);
	}
	//system("pause");
}