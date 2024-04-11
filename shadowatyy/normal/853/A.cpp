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

const int N = 3e5+7;

int n, k;

int c[N];
int res[N];

ll ans;

struct comp
{
	bool operator()(int a, int b)
	{
		return mp(c[a], a)>mp(c[b], b);
	}
};

set<int, comp> S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}

	for(int i = 1; i <= k; ++i)
	{
		S.insert(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(k+i<=n)
			S.insert(k+i);

		res[*S.begin()] = k+i;
		S.erase(S.begin());
	}

	for(int i = 1; i <= n; ++i)
	{
		ans += (ll)c[i]*(res[i]-i);
	}

	cout << ans << endl;

	for(int i = 1; i <= n; ++i)
	{
		cout << res[i] << " ";
	}
}