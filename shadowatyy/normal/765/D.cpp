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

#define N 100007

int n;

int f[N];
int h[N];
int pos[N];

VI val;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> f[i];
		val.pb(f[i]);
	}

	sort(ALL(val));
	val.erase(unique(ALL(val)), val.end());

	for(int i = 0; i < val.size(); ++i)
	{
		if(f[val[i]]!=val[i])
		{
			cout << -1;
			return 0;
		}

		h[i+1] = val[i];
		pos[val[i]] = i+1;
	}

	cout << val.size() << endl;

	for(int i = 1; i <= n; ++i)
	{
		cout << pos[f[i]] << " ";
	}

	cout << endl;

	for(int i = 1; i <= val.size(); ++i)
	{
		cout << h[i] << " ";
	}
}