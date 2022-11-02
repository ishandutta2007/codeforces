#include <iostream>
#include <cstring>
using namespace std;

const int N = 14;
const int M = 101;
typedef long long intl;

int n, m, q;
int edge[N][2];
int lca[M][3];

int lowbit(int x)
{
	return x & (-x);
}

bool check_edge(int mask1, int mask2, int sp1, int sp2)
{
	for(int i = 0; i < m; i ++)
		for(int t = 0; t < 2; t ++)
		{
			if(((mask1 >> edge[i][0]) & 1) && ((mask2 >> edge[i][1]) & 1))
				if(edge[i][0] != sp1 || edge[i][1] != sp2)
					return false;
			swap(edge[i][0], edge[i][1]);
		}
	return true;
}
bool check_lca(int mask1, int mask2, int root)
{
	for(int i = 0; i < q; i ++)
		for(int t = 0; t < 2; t ++)
		{
			if(((mask1 >> lca[i][0]) & 1) && ((mask2 >> lca[i][1]) & 1))
				if(lca[i][2] != root)
					return false;
			swap(lca[i][0], lca[i][1]);
		}
	return true;
}

intl memo[N][1 << N];
intl dp(int root, int mask)
{
	if(mask - lowbit(mask) == 0)
		return 1;
	if(memo[root][mask] != -1)
		return memo[root][mask];
	intl ret = 0;
	mask ^= (1 << root);
	for(int nxt = mask; nxt > 0; nxt = (nxt - 1) & mask)
		if(lowbit(nxt) == lowbit(mask))
			for(int i = 0; i < n; i ++)
				if((nxt >> i) & 1)
				{
					int r = mask ^ nxt ^ (1 << root);
					if(check_edge(nxt, r, i, root) && check_lca(nxt, r, root))
						ret += (intl)dp(i, nxt) * dp(root, r);
				}
	memo[root][mask ^ (1 << root)] = ret;
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i = 0; i < m; i ++)
		for(int j = 0; j < 2; j ++)
		{
			cin >> edge[i][j];
			edge[i][j] --;
		}
	for(int i = 0; i < q; i ++)
	{
		for(int j = 0; j < 3; j ++)
		{
			cin >> lca[i][j];
			lca[i][j] --;
		}
		if(lca[i][0] == lca[i][1] && lca[i][0] != lca[i][2])
		{
			cout << 0 << '\n';
			return 0;
		}
	}
	memset(memo, -1, sizeof(memo));
	cout << dp(0, (1 << n) - 1) << '\n';
	return 0;
}