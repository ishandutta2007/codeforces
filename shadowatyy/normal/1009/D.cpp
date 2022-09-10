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

int n, m;

VPII ans;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	if(m<n-1)
	{
		cout << "Impossible" << endl;
		return 0;
	}

	for(int i = 2; i <= n; ++i)
	{
		ans.eb(1, i);
		--m;
	}

	if(!m)
	{
		cout << "Possible" << endl;

		for(auto it:ans)
			cout << it.st << " " << it.nd << endl;

		return 0;
	}

	for(int i = 2; i <= n; ++i)
	{
		for(int j = 2; j < i; ++j)
		{
			if(__gcd(i, j)==1)
			{
				--m;
				ans.eb(i, j);

				if(!m)
				{
					cout << "Possible" << endl;

					for(auto it:ans)
						cout << it.st << " " << it.nd << endl;

					return 0;
				}
			}
		}
	}

	cout << "Impossible" << endl;
}