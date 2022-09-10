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

#define int long long
const int N = 2e5+7;

int n, T, ans, kiedy = 1, sum;

int p[N];
int t[N];

struct comp
{
	bool operator()(int a, int b)
	{
		return mp(t[a], a)>mp(t[b], b);
	}
};

set<int, comp> S;

VI v[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> T;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i] >> t[i];
		v[p[i]].pb(i);
	}

	for(int i = n; i >= 1; --i)
	{
		for(auto it:v[i])
		{
			S.insert(it);
			sum += t[it];
		}

		while(sum>T || S.size()>i)
		{
			sum -= t[*S.begin()];
			S.erase(S.begin());
		}

		if(S.size()>ans)
		{
			ans = S.size();
			kiedy = i;
		}
	}

	cout << ans << endl;

	S.clear();
	sum = 0;

	for(int i = n; i >= 1; --i)
	{
		for(auto it:v[i])
		{
			S.insert(it);
			sum += t[it];
		}

		while(sum>T || S.size()>i)
		{
			sum -= t[*S.begin()];
			S.erase(S.begin());
		}

		if(i==kiedy)
		{
			cout << S.size() << endl;

			for(auto it:S)
				cout << it << " ";

			exit(0);
		}
	}
}