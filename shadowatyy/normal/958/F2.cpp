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

const int N = 2e5+7;

int n, c, ile_ok, ans = inf, sum;

int a[N];
int k[N];
int cnt[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> c;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= c; ++i)
	{
		cin >> k[i];
		sum += k[i];

		if(!k[i])
			++ile_ok;
	}

	int r = 0;

	for(int l = 1; l <= n; ++l)
	{
		while(ile_ok<c && r<n)
		{
			++r;
			++cnt[a[r]];

			if(cnt[a[r]]==k[a[r]])
				++ile_ok;
		}

		if(ile_ok==c)
			ans = min(ans, r-l+1);

		--cnt[a[l]];

		if(cnt[a[l]]+1==k[a[l]])
			--ile_ok;
	}

	cerr << ans << endl;
		
	if(ans==inf)
		cout << -1 << endl;
	else
		cout << ans-sum << endl;
}