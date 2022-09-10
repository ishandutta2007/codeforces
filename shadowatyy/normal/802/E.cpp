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
#define flush fflush(stdout)
using namespace std;

#define logf hfahuwef

int t;

int a[257];
double logf[3007];

long double calc(int p, int k)
{
	if(k==0)
		return -p;

	return k*log(p)-p-logf[k];
}

long double poisson(int p)
{
	long double res = 0;

	for(int i = 0; i < 250; ++i)
	{
		res += calc(p, a[i]);
	}

	return res;
}

long double uniform(int p)
{
	long double res = 0;

	if(a[0]>2*p)
		return -1e9;

	return 250*log(double(1)/(2*p+1));
}

void solve()
{
	for(int i = 0; i < 250; ++i)
	{
		cin >> a[i];
	}

	sort(a, a+250);
	reverse(a, a+250);

 	int ans = -1;
 	long double best = -1e9;

 	for(int i = 10; i <= 1000; ++i)
 	{
 		long double p = poisson(i);

 		if(p>best)
 		{
 			best = p;
 			ans = i;
 		}
 		
 		long double u = uniform(i);

 		if(u>best)
 		{
 			best = u;
 			ans = i;
 		}
 	}

 	cout << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	srand(time(NULL));

	logf[0] = log(1);

	for(int i = 1; i <= 3000; ++i)
	{
		logf[i] = logf[i-1]+log(i);
	}

	cin >> t;

	while(t--)
		solve();
}