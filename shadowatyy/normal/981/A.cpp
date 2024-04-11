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

int ans;

string s;

bool check(string t)
{	
	for(int i = 0; i < (int)t.size()-1-i; ++i)
	{
		if(t[i]!=t[t.size()-1-i])
			return 1;
	}

	return 0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;

	for(int i = 0; i < s.size(); ++i)
	{
		for(int j = i; j < s.size(); ++j)
		{
			if(check(s.substr(i, j-i+1)))
				ans = max(ans, j-i+1);
		}
	}

	cout << ans << endl;
}