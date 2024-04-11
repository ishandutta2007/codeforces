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

const int N = 5007;

int n, q;

int a[N];
int mx[N][N];
int f[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		f[i][i] = mx[i][i] = a[i];
	}

	for(int l = 2; l <= n; ++l)
	{
		for(int a = 1; a+l-1 <= n; ++a)
		{
			int b = a+l-1;

			f[a][b] = (f[a+1][b]^f[a][b-1]);
			mx[a][b] = max(mx[a+1][b], mx[a][b-1]);
			mx[a][b] = max(mx[a][b], f[a][b]);
		}
	}

	cin >> q;

	while(q--)
	{
		int l, r;
		cin >> l >> r;
		cout << mx[l][r] << endl;
	}
}