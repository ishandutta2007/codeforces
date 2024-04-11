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
#define flush fflush(stdout)
using namespace std;

#define N 1007
#define int long long
#define y1 kdkvskk
#define double long double
#define pi 3.141592653589793238462

int n;

int x[N];
int y[N];
int r[N];

int ile[N];

bitset<N> ok;

double res;

int dist(int x1, int y1, int x2, int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> y[i] >> r[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(i!=j && r[i]<r[j] && dist(x[i], y[i], x[j], y[j])<r[j]*r[j])
				++ile[i];	
		}

		if(ile[i]==1)
		{
			res += pi*r[i]*r[i];
			ok[i] = 1;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(ok[i])
			continue;

		ile[i] = 0;

		for(int j = 1; j <= n; ++j)
		{
			if(!ok[j] && i!=j && r[i]<r[j] && dist(x[i], y[i], x[j], y[j])<r[j]*r[j])
				++ile[i];	
		}

		if(ile[i]%2==0)
			res += pi*r[i]*r[i];
		else
			res -= pi*r[i]*r[i];
	}

	cout << fixed << setprecision(15) << res;
}