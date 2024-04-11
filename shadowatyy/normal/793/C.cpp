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
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
using namespace std;

#define N 100007
#define y1 _y1
#define eps 1e-15
#define double long double

int n, x1, y1, x2, y2;

double amin = 0, amax = 1e9+7;

int rx[N];
int ry[N];
int vx[N];
int vy[N];

double rmin[N], rmax[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> x1 >> y1 >> x2 >> y2;

	if(x1==x2 || y1==y2)
	{
		cout << -1;
		return 0;
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> rx[i] >> ry[i] >> vx[i] >> vy[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		rmin[i] = 0, rmax[i] = 1e9+7;

		if(vx[i])
		{
			double t1 = ((double)x1-rx[i])/vx[i];
			double t2 = ((double)x2-rx[i])/vx[i];

			if(t1>t2)
				swap(t1, t2);

			t1 += eps;
			t2 -= eps;

			rmin[i] = max(rmin[i], t1);
			rmax[i] = min(rmax[i], t2);
		}
		else
		{
			if(rx[i]>x1 && rx[i]<x2)
			{
				rmin[i] = max(rmin[i], (double)0);
				rmax[i] = min(rmax[i], (double)1e9+7);
			}
			else
			{
				rmin[i] = max(rmin[i], (double)1e9+7);
				rmax[i] = min(rmax[i], (double)-1e9+7);
			}
		}

		if(vy[i])
		{
			double t1 = ((double)y1-ry[i])/vy[i];
			double t2 = ((double)y2-ry[i])/vy[i];

			if(t1>t2)
				swap(t1, t2);

			t1 += eps;
			t2 -= eps;

			rmin[i] = max(rmin[i], t1);
			rmax[i] = min(rmax[i], t2);
		}
		else
		{
			if(ry[i]>y1 && ry[i]<y2)
			{
				rmin[i] = max(rmin[i], (double)0);
				rmax[i] = min(rmax[i], (double)1e9+7);
			}
			else
			{
				rmin[i] = max(rmin[i], (double)1e9+7);
				rmax[i] = min(rmax[i], (double)-1e9+7);
			}
		}

		amin = max(amin, rmin[i]);
		amax = min(amax, rmax[i]);
	}

	if(amin>amax)
		cout << -1;
	else
		cout << setprecision(20) << fixed << amin;
}