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

#define y1 sgdfbfdbd
#define N 100007
#define double long double

const double pi = acos(-1.0);

double res, r1 = 1e18, r2 = -1e18;

int n, X, Y;

double x[N];
double y[N];

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> X >> Y;

	for(int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
	}

	for(int i = 0; i < n; ++i)
	{
		int j = (i+1)%n;

		double l = 0, r = 1;

		for(int k = 1; k <= 30; ++k)
		{
			double m1 = l*2.0/3.0+r*1.0/3.0;
			double m2 = l*1.0/3.0+r*2.0/3.0;

			if(dist(x[i]*m1+x[j]*(1.0-m1), y[i]*m1+y[j]*(1.0-m1), X, Y)<dist(x[i]*m2+x[j]*(1.0-m2), y[i]*m2+y[j]*(1.0-m2), X, Y))
				r = m2;
			else
				l = m1;
		}

		r1 = min(r1, dist(x[i]*l+x[j]*(1.0-l), y[i]*l+y[j]*(1.0-l), X, Y));
		r2 = max(r2, dist(X, Y, x[i], y[i]));
	}

	cout << fixed << setprecision(15) << r2*r2*pi-r1*r1*pi;
}