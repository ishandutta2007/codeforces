#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
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

int n, k, res, a, b, ile;

map<int, VI > P;
map<int, VI > K;

VPII p;

VI val;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a >> b;

		P[a].pb(b);
		K[b].pb(a);

		p.eb(a, b);

		val.pb(a);
		val.pb(b);
	}

	a = inf;
	b = -inf;

	sort(ALL(val));
	val.erase(unique(ALL(val)), val.end());

	int B = 0;

	for(int A = 0; A < val.size(); ++A)
	{
		for(auto it:P[val[A]])
		{
			if(it>=val[B])
				++ile;
		}

		if(ile>=k && res<val[B]-val[A]+1)
		{
			res = val[B]-val[A]+1;
			a = val[A];
			b = val[B];
		}

		while(ile>=k && B+1<val.size())
		{
			if(ile>=k && res<val[B]-val[A]+1)
			{
				res = val[B]-val[A]+1;
				a = val[A];
				b = val[B];
			}

			for(auto it:K[val[B]])
			{
				if(it<=val[A])
					--ile;
			}

			++B;

			if(ile>=k && res<val[B]-val[A]+1)
			{
				res = val[B]-val[A]+1;
				a = val[A];
				b = val[B];
			}
		}
	}

	cout << res << endl;

	for(int i = 0; i < n && k; ++i)
	{
		if(p[i].st<=a && p[i].nd>=b)
		{
			cout << i+1 << " ";
			--k;
		}
	}
}