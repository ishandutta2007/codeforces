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

#define int long long

int t, x, y, p, q;

void solve()
{
	cin >> x >> y >> p >> q;

	if(p==1 && q==1)
	{
		if(x==y)
			cout << 0 << endl;
		else
			cout << -1 << endl;
	}
	else if(p==0 && q==1)
	{
		if(x==0)
			cout << 0 << endl;
		else
			cout << -1 << endl;
	}
	else 
	{
		int k1 = (x-y)/(p-q);

		if(k1*(p-q)!=(x-y))
			++k1;

		int k2 = x/p;

		if(k2*p!=x)
			++k2;

		int k3 = y/q;

		if(k3*q!=y)
			++k3;

		int k = max(k1, k2);
		k = max(k, k3);

		cout << k*q-y << endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> t;

	while(t--)
		solve();
}