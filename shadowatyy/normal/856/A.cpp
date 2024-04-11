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
#define SIZE(x) (int)(x).size()
using namespace std;

const int N = 2e6+7;

int t, n;

int a[107];
int b[107];

bitset<N> zle;

VI par;

void solve()
{
	par.clear();
	zle.reset();

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		for(int j = i-1; j >= 1; --j)
		{
			par.pb(max(a[i]-a[j], a[j]-a[i]));
		}
	}

	int curr = 1;

	for(int i = 1; i <= n; ++i)
	{
		while(zle[curr] && curr<1000000)
			++curr;

		if(zle[curr])
		{
			cout << "NO\n";
			return;
		}	

		b[i] = curr;

		for(auto it:par)
		{
			zle[curr+it] = 1;
		}

		++curr;
	}	

	cout << "YES\n";

	for(int i = 1; i <= n; ++i)
	{
		cout << b[i] << " ";
	}

	cout << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> t;

	while(t--)
		solve();
}