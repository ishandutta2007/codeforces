#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

typedef long long ll;

const int N = 1e5 + 5;

int n, m, k, a[N], b[N], sp[N], tot;
bool vis[N];
ll ans;

std::vector<int> q[N];

int main()
{
	int i, j;
	scanf("%d%d", &n, &k);
	For (i, 1, n) scanf("%d", &a[i]), vis[a[i]] = 1;
	For (i, 1, n) scanf("%d", &b[i]), q[a[i]].push_back(b[i]);
	For (i, 1, k) if (!vis[i]) m++;
	For (i, 1, k) std::sort(q[i].begin(), q[i].end());
	For (i, 1, k)
	{
		int tmp = q[i].size();
		For (j, 0, tmp - 2) sp[++tot] = q[i][j];
	}
	std::sort(sp + 1, sp + tot + 1);
	For (i, 1, m) ans += sp[i];
	std::cout << ans << std::endl;
	return 0;
}