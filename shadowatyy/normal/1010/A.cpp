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

#define int ll

const int N = 1e5+7;

int n, m;

int a[N];
int b[N];

bool check(double f)
{
	for(int i = 0; i < n; ++i)
	{
		f -= (f+m)/a[i];
		f -= (f+m)/b[(i+1)%n];
	}

	return f>0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];

		if(a[i]==1)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];

		if(b[i]==1)
		{
			cout << -1 << endl;
			return 0;
		}
	}


	double l = 0, r = 1e9;

	for(int i = 0; i <= 100; ++i)
	{
		double m = (l+r)/2;

		if(check(m))
			r = m;
		else
			l = m;
	}

	cout << fixed << setprecision(15) << l << endl;
}