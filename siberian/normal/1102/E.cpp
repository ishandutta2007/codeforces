#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
#define int long long
const int mod = 998244353;
const int MAXN = 2 * 1e5 + 10;
int tree[4 * MAXN];
map <int, int> fx;
set <int> g;
bool used[MAXN];
map <int, int> help;


void update(int v, int tl, int tr, int l, int r, int val)
{
	if (tl >= r || tr <= l) return;
	if (tl == l && tr == r)
	{
		tree[v] += val;
		return;
	}
	int tm = (tl + tr) / 2;
	update(v * 2, tl, tm, l, r, val);
	update(v * 2 + 1, tm, tr, l, r, val);
	tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r)
{
	if (tl >= r || tr <= l)
		return 0;
	if (tl >= l && tr <= r)
		return tree[v];
	int tm = (tl + tr) / 2;
	int ans = max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
	return ans;
}

signed main() {

	int n, a[MAXN], dp[MAXN][2];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		fx[a[i]]++;
		g.insert(a[i]);
	}

	int pos = 0;
	for (auto i : g)
	{
		help[i] = pos++;
	}

	dp[0][0] = 1;
	dp[0][1] = 0;
	update(1, 0, MAXN - 1, help[a[0]], help[a[0]] + 1, fx[a[0]] - 1);
	used[help[a[0]]] = 1;
	for (int i =1; i < n; i++) {
		dp[i][0] = 0;
		dp[i][1] = 0;
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][0] %= mod;
		if (!used[help[a[i]]])
		{
			int h = get(1, 0, MAXN - 1, 0, MAXN - 10);
			if (h == 0)
			{
				dp[i][1] = dp[i][0];
			}
			update(1, 0, MAXN - 1, help[a[i]], help[a[i]] + 1, fx[a[i]] - 1);
			used[help[a[i]]] = 1;
		}
		else
		update(1, 0, MAXN - 1, help[a[i]], help[a[i]] + 1, -1);
	}

	int ans = dp[n - 1][0] + dp[n - 1][1];
	ans %= mod;
	cout << ans;
	return 0;
}