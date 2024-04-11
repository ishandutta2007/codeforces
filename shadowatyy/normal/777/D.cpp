#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 500007

int n;

string s[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s[i];
	}

	for(int i = n-1; i >= 1; --i)
	{
		if(s[i]<=s[i+1])
			continue;
		else
		{
			for(int j = 0; j < s[i].size(); ++j)
			{
				if(s[i][j]!=s[i+1][j])
				{
					s[i] = s[i].substr(0, j);
					break;
				}
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << s[i] << endl;
	}
}