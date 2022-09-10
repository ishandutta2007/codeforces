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

int n, ans, sum;

int a[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}

	int mx = -1;

	for(int i = n; i >= 1; --i)
	{
		--mx;
		a[i] = max(a[i], mx);
		mx = max(mx, a[i]);
	}

	mx = -1;

	for(int i = 1; i <= n; ++i)
	{
		a[i] = max(a[i], mx);
		mx = max(a[i], mx);
		ans += a[i];
	}

	cout << ans-sum << endl;
}