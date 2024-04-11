#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
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

const int N = 1007;

int n, m, ans;

int c[N];
int a[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i];
	}

	int curr = 1;

	for(int i = 1; i <= n; ++i)
	{
		if(curr<=m && a[curr]>=c[i])
		{
			++curr;
			++ans;
		}
	}

	cout << ans << endl;
}