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

int n;

VI G[N];

VPII ans;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	int cnt = 0, ktory = -1;

	for(int i = 1; i <= n; ++i)
	{
		if(G[i].size()>2)
		{
			++cnt;
			ktory = i;
		}
	}

	if(cnt>1)
	{
		cout << "No" << endl;
		return 0;
	}

	if(ktory==-1)
		ktory = 1;

	for(int i = 1; i <= n; ++i)
	{
		if(i!=ktory && G[i].size()==1)
			ans.eb(ktory, i);
	}

	cout << "Yes" << endl;

	cout << ans.size() << endl;

	for(auto it:ans)
		cout << it.st << " " << it.nd << endl;
}