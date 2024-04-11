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
const int M = 1e18;

int q;

VI v, o;

int solve(int k)
{
	int ans = upper_bound(ALL(v), k)-v.begin();
	ans -= upper_bound(ALL(o), k)-o.begin();

	int s = sqrt(k);

	while(s*s>k)
		--s;

	while((s+1)*(s+1)<=k)
		++s;

	ans += s;
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 2; i*i*i <= M; ++i)
	{
		for(int j = i*i*i; j <= M; j *= i)
		{			
			v.pb(j);

			if(j>M/i)
				break;
		}
	}

	sort(ALL(v));
	v.erase(unique(ALL(v)), v.end());

	for(auto it:v)
	{
		int s = sqrt(it);

		while(s*s>it)
			--s;

		while((s+1)*(s+1)<=it)
			++s;

		if(s*s==it)
			o.pb(it);
	}

	sort(ALL(o));
	o.erase(unique(ALL(o)), o.end());

	cin >> q;

	while(q--)
	{
		int l, r;
		cin >> l >> r;
		cout << solve(r)-solve(l-1) << endl;
	}
}