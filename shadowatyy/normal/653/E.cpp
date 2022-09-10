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

#define N 300007

int n, m, k, a, b, curr, deg;

set<PII> forb;
VI unvis;

queue<int> Q;

int comp[N];
int ok[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k;

	deg = n-1;

	while(m--)
	{
		cin >> a >> b;
		forb.insert({a, b});
		forb.insert({b, a});

		if(a==1 || b==1)
			--deg;
	}

	if(k>deg)
	{
		cout << "impossible";
		return 0;
	}

	for(int i = 2; i <= n; ++i)
	{
		unvis.pb(i);
	}

	while(!unvis.empty())
	{
		int v = unvis.back();
		unvis.pop_back();
		++curr;

		Q.push(v);

		while(!Q.empty())
		{
			int v = Q.front();
			Q.pop();
			comp[v] = curr;

			for(int i = 0; i < unvis.size(); ++i)
			{
				if(forb.find({v, unvis[i]})==forb.end())
				{
					Q.push(unvis[i]);
					swap(unvis[i], unvis.back());
					unvis.pop_back();
					--i;
				}
			}
		}
	}

	if(k<curr)
	{
		cout << "impossible";
		return 0;
	}

	for(int i = 2; i <= n; ++i)
	{
		if(forb.find({1, i})==forb.end())
			ok[comp[i]] = 1;
	}

	for(int i = 1; i <= curr; ++i)
	{
		if(!ok[i])
		{
			cout << "impossible";
			return 0;
		}
	}

	cout << "possible";

}