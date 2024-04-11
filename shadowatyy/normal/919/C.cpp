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

int n, m, k, ans;

char c[N][N];

int l[N][N];
int u[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			cin >> c[i][j];

			if(c[i][j]=='.')
			{
				l[i][j] = 1+l[i][j-1];
				u[i][j] = 1+u[i-1][j];

				if(l[i][j]>=k)
					++ans;

				if(u[i][j]>=k)
					++ans;
			}
		}
	}

	if(k==1)
		ans /= 2;

	cout << ans << endl;
}