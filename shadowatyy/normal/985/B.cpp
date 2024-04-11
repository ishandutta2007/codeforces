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

const int N = 2007;

int n, m;

int a[N][N];
int cnt[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			char c;
			cin >> c;

			if(c=='1')
				a[i][j] = 1;

			cnt[j] += a[i][j];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		bool ok = 1;

		for(int j = 1; j <= m; ++j)
		{
			if(a[i][j] && cnt[j]==1)
				ok = 0;
		}

		if(ok)
		{
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
}