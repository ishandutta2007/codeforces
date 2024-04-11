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

const int N = 107;

int n, c;

int a[N];
int k[N];
int cnt[N];

void check()
{
	for(int i = 1; i <= c; ++i)
	{
		if(cnt[i]!=k[i])
			return;
	}

	cout << "YES" << endl;
	exit(0);
}

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
	}

	for(int i = 1; i <= n; ++i)
	{
		memset(cnt, 0, sizeof cnt);

		for(int j = i; j <= n; ++j)
		{
			++cnt[a[j]];
			check();
		}
	}

	cout << "NO" << endl;
}