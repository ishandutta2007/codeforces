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

#define int long long
const int N = 57;

int n, k, m, sum, ans;

int t[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> m;

	for(int i = 1; i <= k; ++i)
	{
		cin >> t[i];
		sum += t[i];
	}

	sort(t+1, t+1+k);

	for(int i = 0; i <= n && sum*i <= m; ++i)
	{
		int cm = m-sum*i, cr = (k+1)*i;

		for(int j = 1; j <= k; ++j)
		{	
			for(int l = i+1; l <= n; ++l)
			{
				if(cm>=t[j])
				{
					++cr;
					cm -= t[j];
				}
			}
		}

		ans = max(ans, cr);
	}

	cout << ans;
}