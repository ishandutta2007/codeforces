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

int m;

vector<string> t[1000007];

bool read(int d)
{
	m = max(d, m);

	string s = "";

	char c;

	int n;

	cin >> c;

	while(c!=',')
	{
		s += c;

		cin >> c;
	}

	t[d].pb(s);

	cin >> n;

	if(!(cin >> c))
		return 0;

	while(n--)
	{
		read(d+1);
	}

	return 1;
}	

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	while(read(1));

	cout << m << endl;

	for(int i = 1; i <= m; ++i)
	{
		for(auto it:t[i])
		{
			cout << it << " ";
		}

		cout << endl;
	}
		
}