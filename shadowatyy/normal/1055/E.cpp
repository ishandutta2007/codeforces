#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define ll long long
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define VPII vector<PII>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

const int N = 1<<11;

int n, s, m, k;

int a[N];
int b[N];
int pref[N];
int l[N];
int r[N];
int dp[N][N];
int zawierany[N];

VI val;

VI koniec[N];

int sp[12][N];

void build(int j)
{
	for(int i = 0; i <= n; ++i)
	{
		sp[0][i] = dp[i][j] - pref[i];
	}

	for(int l = 1; l < 12; ++l)
	{
		for(int i = 0; i <= n; ++i)
		{
			if(i+(1<<(l-1))<=n)
				sp[l][i] = max(sp[l-1][i], sp[l-1][i+(1<<(l-1))]);
		}
	}
}

inline int query(int a, int b)
{
	int d = b-a+1;
	int log = 31-__builtin_clz(d);
	return max(sp[log][a], sp[log][b-(1<<log)+1]);
}

void prep(int x)
{
	for(int i = 1; i <= n; ++i)
	{
		if(a[i]<=x)
			b[i] = 1;
		else
			b[i] = 0;
	}

	for(int i = 1; i <= n; ++i)
	{
		pref[i] = pref[i-1] + b[i];
	}
}

void calc()
{
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			dp[i][j] = 0;
		}
	}

	build(0);

	for(int j = 1; j <= s; ++j)
	{
		for(int i = 1; i <= n; ++i)
		{	
			for(auto it:koniec[i])
			{
				dp[i][j] = max(dp[i][j], query(it-1, i-1) + pref[i]);
			}
		}

		for(int i = 1; i <= n; ++i)
		{
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}

		build(j);
	}
}

bool check(int x)
{
	prep(x);
	calc();

	for(int i = 1; i <= m; ++i)
	{
		if(dp[n][i]>=k)
			return 1;
	}

	return 0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> s >> m >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		val.pb(a[i]);
	}

	for(int i = 1; i <= s; ++i)
	{
		cin >> l[i] >> r[i];
	}

	for(int i = 1; i <= s; ++i)
	{
		for(int j = 1; j <= s; ++j)
		{
			if(mp(l[i], r[i])!=mp(l[j], r[j]) && l[i]<=l[j] && r[j]<=r[i])
				zawierany[j] = 1;
		}
	}

	for(int i = 1; i <= s; ++i)
	{
		if(!zawierany[i])
			koniec[r[i]].pb(l[i]);
	}

	sort(ALL(val));
	val.erase(unique(ALL(val)), val.end());

	int l = 0, r = val.size()-1;

	while(l<r)
	{
		int m = (l+r)/2;

		if(check(val[m]))
			r = m;
		else
			l = m+1;
	}

	if(!check(val[l]))
		cout << -1 << endl;
	else
		cout << val[l] << endl;
}