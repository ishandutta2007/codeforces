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

#define int long long

int n, p, q, b;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	while(n--)
	{
		cin >> p >> q >> b;

		int g = __gcd(p, q);
		p /= g;
		q /= g;

		while(q>1)
		{
			int g = __gcd(q, b);

			if(g==1)
			{
				cout << "Infinite" << endl;
				break;
			}
			else
			{
				while(q%g==0)
					q /= g;
			}
		}

		if(q==1)
			cout << "Finite" << endl;
	}
}