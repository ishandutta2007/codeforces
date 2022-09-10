#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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

const int N = 1007;

int m;

int s[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> s[i];
	}

	int g = s[1];

	for(int i = 2; i <= m; ++i)
	{
		g = __gcd(g, s[i]);
	}

	if(g!=s[1])
	{
		cout << -1;
		return 0;
	}
	else
	{
		cout << 2*m-1 << endl;

		for(int i = 1; i < m; ++i)
		{
			cout << s[i] << " " << g << " ";
		}

		cout << s[m];
	}
}