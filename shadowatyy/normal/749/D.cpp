#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

#define N 200007

int n, q, k, p, v;

VI Q;

VI bids[N];

struct comp
{	
	bool operator()(const int &a, const int &b)
	{
		return bids[a].back()>bids[b].back();
	}
};

set<int, comp> S;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p >> v;

		bids[p].pb(v);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!bids[i].empty())
			S.insert(i);
	}

	cin >> q;

	while(q--)
	{
		Q.clear();

		cin >> k;

		for(int i = 0; i < k; ++i)
		{
			cin >> p;

			if(!bids[p].empty())
			{
				S.erase(p);
			}

			Q.pb(p);
		}

		if(S.empty())
		{
			cout << 0 << " " << 0 << endl;
		}
		else
		{
			if(S.size()==1)
			{
				cout << *S.begin() << " " << bids[*S.begin()][0] << endl;
			}
			else
			{
				cout << *S.begin() << " " << *lower_bound(bids[*S.begin()].begin(), bids[*S.begin()].end(), bids[*(++S.begin())].back()) << endl;
			}
		}

		for(int i = 0; i < k; ++i)
		{
			if(!bids[Q[i]].empty())
			{
				S.insert(Q[i]);
			}
		}
	}
}