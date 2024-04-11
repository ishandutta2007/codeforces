#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
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

int n;

string s;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	n = s.size();
	s = '#' + s;

	int cnt0 = 0;
	int cnt1 = 0;
	int byla2 = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(s[i]=='2')
			byla2 = 1;
		
		if(s[i]=='0' && !byla2)
			++cnt0;

		if(s[i]=='1')
			++cnt1;
	}

	for(int i = 0; i < cnt0; ++i)
		cout << 0;

	for(int i = 0; i < cnt1; ++i)
		cout << 1;

	byla2 = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(s[i]=='2')
		{
			cout << 2;
			byla2 = 1;
		}
		else if(s[i]=='0' && byla2)
			cout << 0;
	}
}