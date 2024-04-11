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

#define N 200007

int n, b, cb, cc;

int p[N];

bitset<N> vis;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> b;

		if(b)
			++cb;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			++cc;
			int v = i;
			vis[v] = 1;

			while(!vis[p[v]])
			{
				v = p[v];
				vis[v] = 1;
			}
		}
	}

	if(cc==1)
	{
		if(cb%2)
			cout << 0;
		else
			cout << 1;
	}
	else
	{
		if(cb%2)
			cout << cc;
		else
			cout << cc+1;
	}
}