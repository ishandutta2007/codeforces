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

int n, m, x, y, vx, vy;

int fpow(int a, int b, int mod)
{
	int ans = 1;

	while(b)
	{
		if(b&1)
			ans = ans*a%mod;
		
		a = a*a%mod;
		b /= 2;
	}

	return ans;
}

int phi(int a)
{
	int res = a, curr = a;

	for(int i = 2; i*i <= a; ++i)
	{
		if(curr%i==0)
			res -= res/i;

		while(curr%i==0)
			curr /= i;
	}

	if(curr>1)
		res -= res/curr;

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> x >> y >> vx >> vy;

	if(!vx)
	{
		if(x==0)
		{
			if(vy==1)
				cout << 0 << " " << m << endl;
			else
				cout << 0 << " " << 0 << endl;
		}
		else if(x==n)
		{
			if(vy==1)
				cout << n << " " << m << endl;
			else
				cout << n << " " << 0 << endl;
		}
		else
			cout << -1 << endl;

		return 0;
	}

	if(!vy)
	{
		if(y==0)
		{
			if(vx==1)
				cout << n << " " << 0 << endl;
			else
				cout << 0 << " " << 0 << endl;
		}
		else if(y==m)
		{
			if(vx==1)
				cout << n << " " << m << endl;
			else
				cout << 0 << " " << m << endl;
		}
		else
			cout << -1 << endl;

		return 0;
	}

	int ile = -1;

	if(vx==1)
		ile = (n-x)/vx;
	else
		ile = (0-x)/vx;

	x += ile*vx;
	y += ile*vy;

	int dy = m-y;
	int g = __gcd(n, m);

	if(dy%g)
		cout << -1 << endl;
	else
	{
		int k = dy/g*fpow(n/g, phi(m/g)-1, m/g)%(m/g);
		k *= vy;
		k %= m/g;
		k += m/g;
		k %= m/g;

		x += k*n*vx;
		y += k*n*vy;

		int ax = abs(x/n)%2;
		int ay = abs(y/m)%2;

		cout << ax*n << " " << ay*m << endl;
	}
}