#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define flush fflush(stdout)
using namespace std;

#define N 100007

int n, m, curr, a, b;

VI T[N];

int res[N];
int deg[N];

set<int, greater<int> > S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	curr = n;

	while(m--)
	{
		cin >> a >> b;
		T[b].pb(a);
		++deg[a];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!deg[i])
			S.insert(i);
	}

	while(!S.empty())
	{
		int v = *S.begin();
		S.erase(S.begin());

		res[v] = curr--;

		for(auto it:T[v])
		{
			if(--deg[it]==0)
				S.insert(it);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << res[i] << " ";
	}
}