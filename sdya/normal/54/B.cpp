#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
#include <bitset>

using namespace std;

struct tile
{
	char c[30][30];
};

int n, m;
char s[30][30];

bool good[30][30];

vector < tile > V;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; i ++)
		gets(s[i]);

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (n % i == 0 && m % j == 0)
			{
				V.clear();
				for (int i1 = 0; i1 < n / i; i1 ++)
					for (int j1 = 0; j1 < m / j; j1 ++)
					{
						tile X;
						for (int k = 0; k < i; k ++)
							for (int l = 0; l < j; l ++)
								X.c[k][l] = s[i1 * i + k][j1 * j + l];
						V.push_back(X);
					}
				bool have = true;
				for (int k = 0; k < V.size() && have; k ++)
					for (int l = 0; l < k && have; l ++)
					{
						bool g = false;
						for (int i1 = 0; i1 < i && !g; i1 ++)
							for (int j1 = 0; j1 < j && !g; j1 ++)
								if (V[k].c[i1][j1] != V[l].c[i1][j1]) g = true;
						if (!g) {have = false; break;}
						if (g)
						{
							g = false;
							for (int i1 = 0; i1 < i && !g; i1 ++)
								for (int j1 = 0; j1 < j && !g; j1 ++)
									if (V[k].c[i1][j1] != V[l].c[i - 1 - i1][j - 1 - j1]) g = true;

							if (!g) {have = false; break;}
							if (g && i == j)
							{
								g = false;
								for (int i1 = 0; i1 < i && !g; i1 ++)
									for (int j1 = 0; j1 < j && !g; j1 ++)
										if (V[k].c[i1][j1] != V[l].c[j1][i - 1 - i1]) g = true;
								if (!g) {have = false; break;}
								g = false;
								for (int i1 = 0; i1 < i && !g; i1 ++)
									for (int j1 = 0; j1 < j && !g; j1 ++)
										if (V[k].c[i1][j1] != V[l].c[j - 1 - j1][i1]) g = true;
								if (!g) {have = false; break;}
							}
						}
					}
				if (have) good[i][j] = true;
			}

	int res = 1000000, x, y;
	int ans = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (good[i][j])
			{
				ans ++;
				if (i * j < res) res = i * j, x = i, y = j; else
					if (i * j == res && i < x) x = i, y = j;
			}

	cout << ans << endl;
	cout << x << " " << y << endl;
	return 0;
}