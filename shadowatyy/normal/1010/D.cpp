#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
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

const int N = 1e6+7;

int n;

string t[N];
int l[N];
int r[N];
bool val[N];
bool dp[N];
bool zmiana[N];

void dfs1(int v)
{
	if(t[v]=="AND")
	{
		dfs1(l[v]);
		dfs1(r[v]);
		dp[v] = bool(dp[l[v]] && dp[r[v]]);
	}
	else if(t[v]=="OR")
	{
		dfs1(l[v]);
		dfs1(r[v]);
		dp[v] = bool(dp[l[v]] || dp[r[v]]);
	}
	else if(t[v]=="XOR")
	{
		dfs1(l[v]);
		dfs1(r[v]);
		dp[v] = bool(dp[l[v]] ^ dp[r[v]]);
	}
	else if(t[v]=="NOT")
	{
		dfs1(l[v]);
		dp[v] = !dp[l[v]];
	}
	else if(t[v]=="IN")
		dp[v] = val[v];
}

void dfs2(int v)
{
	if(t[v]=="AND")
	{
		if(dp[l[v]])
			zmiana[r[v]] = zmiana[v];

		if(dp[r[v]])
			zmiana[l[v]] = zmiana[v];

		dfs2(l[v]);
		dfs2(r[v]);
	}
	else if(t[v]=="OR")
	{
		if(!dp[l[v]])
			zmiana[r[v]] = zmiana[v];

		if(!dp[r[v]])
			zmiana[l[v]] = zmiana[v];

		dfs2(l[v]);
		dfs2(r[v]);
	}
	else if(t[v]=="XOR")
	{
		zmiana[r[v]] = zmiana[v];
		zmiana[l[v]] = zmiana[v];

		dfs2(l[v]);
		dfs2(r[v]);
	}
	else if(t[v]=="NOT")
	{
		zmiana[l[v]] = zmiana[v];
		dfs2(l[v]);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];

		if(t[i]=="AND" || t[i]=="OR" || t[i]=="XOR")
			cin >> l[i] >> r[i];
		else if(t[i]=="NOT")
			cin >> l[i];
		else if(t[i]=="IN")
			cin >> val[i];
	}

	dfs1(1);
	zmiana[1] = 1;
	dfs2(1);

	for(int i = 1; i <= n; ++i)
	{
		if(t[i]=="IN")
			cout << int(zmiana[i]^dp[1]);
	}
}