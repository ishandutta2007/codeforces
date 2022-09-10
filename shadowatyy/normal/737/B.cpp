#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
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

int n, a, d, k, ile;

string s;

int t[N];

VI res;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> a >> d >> k >> s;

	s = '#' + s;

	for(int i = n; i >= 1; --i)
	{
		if(s[i]=='0')
		{
			t[i] = t[i+1]+1;
			t[i+1] = 0;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		ile += t[i]/d;
	}

	for(int i = 1; i <= n && ile>=a; ++i)
	{
		if(t[i]>=d)
		{
			--ile;
			res.pb(i+d-1);
			t[i+d] += t[i]-d;
		}
	}

	cout << res.size() << endl;

	for(auto it:res)
	{
		cout << it << " ";
	}
}