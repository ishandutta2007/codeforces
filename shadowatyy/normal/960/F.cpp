#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

const int N = 1e5+7;

int n, m, ans;

VI val[N];

int a[N];
int b[N];
int c[N];
int dp[N];

struct tree
{
	int N;
	VI load;

	void insert(int a, int v)
	{
		a += N;

		while(a>=1)
		{
			load[a] = max(load[a], v);
			a /= 2;
		}
	}

	int query(int a, int b)
	{
		if(a>b)
			return 0;

		a += N;
		b += N;

		int res = max(load[a], load[b]);

		while(a<b-1)
		{
			if(a%2==0)
				res = max(res, load[a+1]);

			if(b%2==1)
				res = max(res, load[b-1]);

			a /= 2;
			b /= 2;
		}

		return res;
	}
};

tree T[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i] >> b[i] >> c[i];
		val[a[i]].pb(c[i]);
		val[b[i]].pb(c[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		sort(ALL(val[i]));
		val[i].erase(unique(ALL(val[i])), val[i].end());

		T[i].N = 1;

		while(T[i].N<val[i].size())
			T[i].N *= 2;

		T[i].load.assign(2*T[i].N, 0);
	}

	for(int i = 1; i <= m; ++i)
	{
		int ind_a = lower_bound(ALL(val[a[i]]), c[i])-val[a[i]].begin();
		int ind_b = lower_bound(ALL(val[b[i]]), c[i])-val[b[i]].begin();

		dp[i] = 1 + T[a[i]].query(0, ind_a-1);

		T[b[i]].insert(ind_b, dp[i]);

		ans = max(ans, dp[i]);
	}


	cout << ans << endl;
}