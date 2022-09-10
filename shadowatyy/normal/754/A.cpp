#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
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

int n, sum, p;

int t[107];

VPII res;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];
	}

	p = 1;

	for(int i = 1; i <= n; ++i)
	{
		sum += t[i];

		if(sum!=0)
		{
			res.eb(p, i);
			p = i+1;
			sum = 0;
		}
		else
		{
			if(i==n)
			{
				if(res.empty())
				{
					cout << "NO";
					return 0;
				}
				else
					res.back().nd = n;
			}
		}
	}

	cout << "YES\n";

	cout << res.size() << endl;

	for(auto it:res)
	{
		cout << it.st << " " << it.nd << endl;
	}
}