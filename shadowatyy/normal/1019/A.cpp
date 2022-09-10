#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VLL = vector<ll>;
using PII = pair<int, int>;
using VPII = vector<PII>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

#define int ll
const int N = 3007;

int n, m;

int p[N];
int c[N];

VI vec;

int curr[N];

bitset<N> vis;

int solve(int k)
{
	for(int i = 1; i <= m; ++i)
	{
		curr[i] = 0;
	}

	for(int i = 1; i <= n; ++i)
	{
		++curr[p[i]];
	}

	vis.reset();

	int ans = 0;

	for(auto it:vec)
	{
		if(p[it]!=1 && curr[p[it]]>=k)
		{
			--curr[p[it]];
			vis[it] = 1;
			ans += c[it];
			++curr[1];
		}
	}

	for(auto it:vec)
	{
		if(!vis[it] && p[it]!=1 && curr[1]<k)
		{
			--curr[p[it]];
			vis[it] = 1;
			ans += c[it];
			++curr[1];
		}
	}

	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i] >> c[i];
		vec.pb(i);
	}

	sort(ALL(vec), [](int a, int b)
	{
		return c[a]<c[b];
	});

	int ans = INF;

	for(int i = 1; i <= n; ++i)
	{
		ans = min(ans, solve(i));
	}

	cout << ans << endl;
}