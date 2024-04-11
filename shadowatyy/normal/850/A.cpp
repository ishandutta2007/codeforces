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
#define SIZE(x) (int)(x).size()
using namespace std;

#define double long double
const int N = 1007;
const double pi = acos(-1);
const double eps = 1e-9;

int n;

int a[N];
int b[N];
int c[N];
int d[N];
int e[N];

VI p;

bitset<N> zly;

double len(double a, double b, double c, double d, double e)
{
	return sqrt(a*a+b*b+c*c+d*d+e*e);
}

bool check(int i, int j, int k)
{
	double l = (a[j]-a[i])*(a[k]-a[i]) + (b[j]-b[i])*(b[k]-b[i]) + (c[j]-c[i])*(c[k]-c[i]) + (d[j]-d[i])*(d[k]-d[i]) + (e[j]-e[i])*(e[k]-e[i]);
	double m = len(a[j]-a[i], b[j]-b[i], c[j]-c[i], d[j]-d[i], e[j]-e[i])*len(a[k]-a[i], b[k]-b[i], c[k]-c[i], d[k]-d[i], e[k]-e[i]);

	return acos(l/m)<pi/2;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	srand(time(NULL));

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
		p.pb(i);
	}

	random_shuffle(ALL(p));

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			for(int k = 0; k < n; ++k)
			{
				if(i!=j && i!=k && j!=k && check(p[i], p[j], p[k]))
					zly[p[i]] = 1;

				if(zly[p[i]])
					break;
			}

			if(zly[p[i]])
				break;
		}
	}

	cout << n-zly.count() << endl;

	for(int i = 1; i <= n; ++i)
	{
		if(!zly[i])
			cout << i << endl;
	}
}