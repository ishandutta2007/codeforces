#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

const int N = 107;

int n, m;

int a[N];
int b[N];
int ans[N][N];

void solve(int q)
{
	int cnt = 0;

	for(int i = 1; i < n; ++i)
	{
		if(a[i]&(1<<q))
		{
			ans[i][m] |= 1<<q;
			cnt ^= 1;
		}
	}

	int x = 0;

	if(bool(cnt)!=bool(b[m]&(1<<q)))
	{
		ans[n][m] |= 1<<q;
		x ^= 1;
	}

	for(int i = 1; i < m; ++i)
	{
		if(b[i]&(1<<q))
		{
			ans[n][i] |= 1<<q;
			x ^= 1;
		}
	}

	if(bool(x)!=bool(a[n]&(1<<q)))
	{
		cout << "NO" << endl;
		exit(0);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> b[i];
	}

	for(int b = 0; b <= 30; ++b)
	{
		solve(b);
	}

	cout << "YES" << endl;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			cout << ans[i][j] << " ";
		}

		cout << endl;
	}
}