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

#define double long double
#define int long long

const int N = 1007;
const double eps = 1e-9;

int n, r;

int x[N];

double ans[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> r;

	cout << fixed << setprecision(10);

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i];	

		ans[i] = r;

		for(int j = 1; j < i; ++j)
		{
			if(abs(x[i]-x[j])-eps>2*r)
				continue;

			double kw = 4*r*r-(x[j]-x[i])*(x[j]-x[i]);
			kw = sqrtl(kw);
			ans[i] = max(ans[i], ans[j]+kw);
		}

		cout << ans[i] << " ";
	}
}