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

#define T 1001007

int n, q, t, sum, s;

set<int> S;

VI p[T];

int k[T];
int d[T];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 1; i <= n; ++i)
	{
		S.insert(i);
	}

	for(int i = 1; i <= q; ++i)
	{
		cin >> t;

		cin >> k[t] >> d[t];
	}

	for(int i = 1; i < T; ++i)
	{
		while(!p[i].empty())
		{
			S.insert(p[i].back());
			p[i].pop_back();
		}

		if(k[i]==0)
			continue;

		if(S.size()<k[i])
		{
			cout << "-1\n";
			continue;
		}

		sum = 0;

		while(k[i]--)
		{
			s = *S.begin();
			S.erase(S.begin());
			sum += s;

			p[i+d[i]].pb(s);
		}

		cout << sum << endl;
	}
}