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

#define int ll

int n, ans;

map<int, int> mx, my;
map<PII, int> mxy;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		int x, y;
		cin >> x >> y;
		++mx[x];
		++my[y];
		++mxy[{x, y}];
	}

	for(auto it:mx)
	{
		ans += it.nd*(it.nd-1)/2;
	}

	for(auto it:my)
	{
		ans += it.nd*(it.nd-1)/2;
	}

	for(auto it:mxy)
	{
		ans -= it.nd*(it.nd-1)/2;
	}

	cout << ans << endl;
}