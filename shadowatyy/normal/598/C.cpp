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

#define double long double
#define int long long
#define N 100007

int n, a, b;

int x[N];
int y[N];

double res = inf;

vector<pair<double, int> > ang;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);


	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> y[i];
		double angle = atan2(y[i], x[i]);

		if(angle<0)
			angle += 2*acos(-1);

		ang.eb(angle, i);
		}

	sort(ALL(ang));

	for(auto it:ang)
		cerr << it.st << " ";

	for(int i = 0; i < n; ++i)
	{
		if(fabs(ang[i].st-ang[(i+1)%n].st)<res)
		{
			res = fabs(ang[i].st-ang[(i+1)%n].st);
			a = ang[i].nd;
			b = ang[(i+1)%n].nd;
		}

		if(fabs(ang[i].st-ang[(i+1)%n].st-2*acos(-1))<res)
		{
			fabs(ang[i].st-ang[(i+1)%n].st-2*acos(-1));
			a = ang[i].nd;
			b = ang[(i+1)%n].nd;
		}

		if(fabs(ang[i].st-ang[(i+1)%n].st+2*acos(-1))<res)
		{
			res = fabs(ang[i].st-ang[(i+1)%n].st+2*acos(-1));
			a = ang[i].nd;
			b = ang[(i+1)%n].nd;
		}
	}

	cout << a << " " << b;
}