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

int n;

set<int> curr, S;

VI c;

string s;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	n = s.size();

	for(int i = 0; i < n; ++i)
	{
		S.insert(i);

		if(i>0 && s[i-1]!=s[i])
			curr.insert(i);
		else if(i+1<n && s[i+1]!=s[i])
			curr.insert(i);
	}

	int ans = 0;

	while(!curr.empty())
	{
		++ans;

		for(auto it:curr)
		{
			S.erase(it);
		}

		for(auto it:curr)
		{
			auto f = S.upper_bound(it);

			if(f!=S.end())
				c.pb(*f);

			if(f!=S.begin())
				c.pb(*prev(f));
		}

		curr.clear();

		sort(ALL(c));
		c.erase(unique(ALL(c)), c.end());

		for(auto it:c)
		{
			auto f = S.find(it);

			if(next(f)!=S.end() && s[*next(f)]!=s[*f])
				curr.insert(*f);
			else if(f!=S.begin() && s[*prev(f)]!=s[*f])
				curr.insert(*f);
		}

		c.clear();
	}

	cout << ans;
}