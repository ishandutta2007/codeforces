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

string s;

bool ok = 1;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> s;

	for(int i = 0; i+1 < n; ++i)
	{
		if(s[i]=='1' && s[i+1]=='1')
			ok = 0;
	}

	if(!ok)
	{
		cout << "No" << endl;
		return 0;
	}

	for(int i = 0; i+2 < n; ++i)
	{
		if(s[i]=='0' && s[i+1]=='0' && s[i+2]=='0')
		{
			cout << "No" << endl;
			return 0;
		}
	}

	if(n>=2 && s[n-1]=='0' && s[n-2]=='0')
	{
		cout << "No" << endl;
		return 0;
	}

	if(n>=2 && s[0]=='0' && s[1]=='0')
	{
		cout << "No" << endl;
		return 0;
	}

	if(n==1 && s[0]=='0')
	{
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
}