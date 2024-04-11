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

const int N = 5e5+7;

int n, k;

ll res;

ll x[N];
ll cost[N];

struct comp
{
	bool operator()(int a, int b)
	{
		return mp(cost[a], a)<mp(cost[b], b);
	}
};

set<int, comp> S;
set<int> P;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> k >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i];
	}

	sort(x+1, x+1+n);

	for(int i = 1; i < n; ++i)
	{
		cost[i] = x[i+1]-x[i];
		P.insert(i);
		S.insert(i);
	}

	for(int i = 1; i <= k; ++i)
	{
		int v = *S.begin();
		S.erase(S.begin());
		
		auto it = P.find(v);

		res += cost[v];

		bool wrzucam = (next(it)!=P.end() && it!=P.begin());

		cost[v] *= -1;

		int a = -1, b = -1;

		if(it!=P.begin())
		{
			cost[v] += cost[*prev(it)];
			S.erase(*prev(it));
			P.erase(*prev(it));
		}

		if(next(it)!=P.end())
		{
			cost[v] += cost[*next(it)];
			S.erase(*next(it));
			P.erase(*next(it));
		}

		if(wrzucam)
			S.insert(v);
		else
			P.erase(v);
	}

	cout << res << endl;
}