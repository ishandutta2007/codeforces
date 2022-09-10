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

const int MOD = 1e9+7;
const int P = 29;
const int N = 2007;

int n, m;

int pot[N*N];

char A[N][N];
char B[N][N];

int ha[N][N];
int hb[N][N];

map<int, int> ma;

int licza(int r)
{
	int curr = 1, ans = 0;

	for(int i = r; i <= r+m-1; ++i)
	{
		ans += ha[i][m]*pot[n-m]%MOD*curr%MOD;
		ans %= MOD;

		curr *= pot[n];
		curr %= MOD;
	}

	return ans;
}

int liczb(int c)
{
	int curr = 1, ans = 0;

	for(int i = 1; i <= m; ++i)
	{
		ans += (hb[i][c+m-1]-hb[i][c-1]+MOD)*pot[n-(c+m-1)]%MOD*curr%MOD;
		ans %= MOD;

		curr *= pot[n];
		curr %= MOD;
	}

	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	pot[0] = 1;

	for(int i = 1; i <= n*n; ++i)
	{
		pot[i] = pot[i-1]*P%MOD;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			cin >> A[i][j];

			ha[i][j] = (ha[i][j-1] + pot[j]*A[i][j])%MOD;
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			cin >> B[i][j];

			hb[i][j] = (hb[i][j-1] + pot[j]*B[i][j])%MOD;
		}
	}

	for(int i = 1; i+m-1 <= n; ++i)
	{
		ma[licza(i)] = i;
	}

	for(int i = 1; i+m-1 <= n; ++i)
	{
		int l = liczb(i);

		if(ma.find(l)!=ma.end())
		{
			cout << ma[l] << " " << i << endl;
			return 0;
		}
	}
}