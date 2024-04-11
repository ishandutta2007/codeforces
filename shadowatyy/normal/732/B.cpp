#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

int n, k, res;

int a[507];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 2; i <= n; ++i)
	{
		if(a[i]+a[i-1]<k)
		{
			res += k-a[i]-a[i-1];
			a[i] += k-a[i]-a[i-1];
		}
	}

	cout << res << endl;

	for(int i = 1; i <= n; ++i)
	{
		cout << a[i] << " ";
	}

}