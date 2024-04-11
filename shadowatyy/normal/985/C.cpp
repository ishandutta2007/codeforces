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

int n, k, l, ans;

int a[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> l;

	for(int i = 1; i <= n*k; ++i)
	{
		cin >> a[i];
	}

	sort(a+1, a+1+n*k);

	int dokad = -1;

	for(int i = 1; i <= n*k; ++i)
	{
		if(a[i]-a[1]<=l)
			dokad = i;
	}

	if(dokad<n)
	{
		cout << 0 << endl;
		return 0;
	}

	int mam = 0, moge = 0;

	for(int i = 1; i <= n*k; ++i)
	{
		//cerr << i << " " << mam << " " << dokad << " " << moge << endl;

		if(!moge || (i<=dokad && mam+(dokad-i+1)==n))
		{
			ans += a[i];
			++mam;
			moge += k;
		}

		--moge;
	}

	cout << ans << endl;
}