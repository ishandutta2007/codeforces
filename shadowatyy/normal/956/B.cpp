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
const int N = 1e5+7;

int n, u;

double ans = -1;

int e[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> u;

	for(int i = 1; i <= n; ++i)
	{
		cin >> e[i];
	}

	int r = 1;

	for(int l = 1; l <= n; ++l)
	{
		while(r+1<=n && e[r+1]-e[l]<=u)
			++r;

		if(l+1<r)
			ans = max(ans, double(e[r]-e[l+1])/(e[r]-e[l]));
	}

	if(ans<-0.5)
		cout << -1 << endl;
	else
		cout << fixed << setprecision(10) << ans << endl;
}