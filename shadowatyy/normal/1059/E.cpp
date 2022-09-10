#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define int ll
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

const int N = 1e5+7;

int n, L, S;

VI G[N];

int w[N];
int ile[N];
int daleko[N];
int sam[N];

VI path;

void dfs(int v)
{
	path.pb(w[v]);

	if(path.size()>1)
		path.back() += path[path.size()-2];

	int l = 1, r = min((int)path.size(), L);

	while(l<r)
	{
		int m = (l+r)/2;

		if(l==m)
			++m;

		if(path.back()-(m==path.size()?0:path[path.size()-m-1])<=S)
			l = m;
		else
			r = m-1;
	}

	sam[v] = l;

	if(G[v].empty())
	{
		ile[v] = 1;
		daleko[v] = sam[v];
	}
	else
	{
		ile[v] = 0;
		daleko[v] = -1;

		for(auto it:G[v])
		{
			dfs(it);
			ile[v] += ile[it];
			daleko[v] = max(daleko[v], daleko[it]);
		}

		--daleko[v];

		if(daleko[v]==0)
		{
			++ile[v];
			daleko[v] = sam[v];
		}
	}

	path.pop_back();
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> L >> S;

	for(int i = 1; i <= n; ++i)
	{
		cin >> w[i];

		if(w[i]>S)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	for(int i = 2; i <= n; ++i)
	{
		int a;
		cin >> a;
		G[a].pb(i);
	}

	dfs(1);
	cout << ile[1] << endl;
}