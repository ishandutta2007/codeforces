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
#define flush fflush(stdout)
using namespace std;

#define N 200007

int n, k;

int d[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1, curr = 1; i <= n-1; ++i, ++curr)
	{
		if(curr==k+1)
			curr = 1;

		++d[curr];
	}

	cout << d[1]+d[2] << endl;

	int l = 1;

	for(int i = 1; i <= k; ++i)
	{
		cout << 1 << " ";
		cout << ++l << endl;

		for(int j = 2; j <= d[i]; ++j)
		{
			cout << l << " ";
			cout << ++l << endl;
		}
	}
}