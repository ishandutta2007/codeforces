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

string s;

int t[256];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;

	t['a'] = 1;
	t['e'] = 1;
	t['i'] = 1;
	t['o'] = 1;
	t['u'] = 1;
	t['1'] = 1;
	t['3'] = 1;
	t['5'] = 1;
	t['7'] = 1;
	t['9'] = 1;

	int res = 0;

	t['e'] = 1;

	for(int i = 0; i < s.size(); ++i)
	{
		if(t[s[i]])
			++res;
	}

	cout << res;
}