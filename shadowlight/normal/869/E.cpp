#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 2505;

int n, m, q;
ll f[2][MAX_N][MAX_N];
map<vector<int>, ll> num_of[2];

ll get(ll f[MAX_N][MAX_N], int a, int b)
{
	ll ans = 0;
	for (int i = a; i > -1; i = (i & (i + 1)) - 1)
		for (int j = b; j > -1; j = (j & (j + 1)) - 1)
			ans += f[i][j];
	return ans;
}

void upd(ll f[MAX_N][MAX_N], int a, int b, ll x)
{
	for (int i = a; i <= n; i = (i | (i + 1)))
		for (int j = b; j <= m; j = (j | (j + 1)))
			f[i][j] += x;
}

ll my_rand()
{
	return (rand() << 15) ^ rand();
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < q; ++i)
	{
		int x1, y1, x2, y2, t;
		scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
		
		if (t == 1)
		{
			ll g1 = num_of[0][{x1, y1, x2, y2}] = my_rand();
			ll g2 = num_of[1][{x1, y1, x2, y2}] = my_rand();
			
			upd(f[0], x1, y1, g1);
			upd(f[0], x2 + 1, y1, -g1);
			upd(f[0], x1, y2 + 1, -g1);
			upd(f[0], x2 + 1, y2 + 1, g1);
		
			upd(f[1], x1, y1, g2);
			upd(f[1], x2 + 1, y1, -g2);
			upd(f[1], x1, y2 + 1, -g2);
			upd(f[1], x2 + 1, y2 + 1, g2);
		}
		else if (t == 2)
		{
			ll g1 = -num_of[0][{x1, y1, x2, y2}];
			ll g2 = -num_of[1][{x1, y1, x2, y2}];
			
			upd(f[0], x1, y1, g1);
			upd(f[0], x2 + 1, y1, -g1);
			upd(f[0], x1, y2 + 1, -g1);
			upd(f[0], x2 + 1, y2 + 1, g1);
		
			upd(f[1], x1, y1, g2);
			upd(f[1], x2 + 1, y1, -g2);
			upd(f[1], x1, y2 + 1, -g2);
			upd(f[1], x2 + 1, y2 + 1, g2);

		}
		else
		{
			if (get(f[0], x1, y1) == get(f[0], x2, y2) &&
				get(f[1], x1, y1) == get(f[1], x2, y2))
				printf("Yes\n");
			else
				printf("No\n");
		}

	}

	return 0;
}