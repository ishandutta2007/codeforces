#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VLL = vector<ll>;
using PII = pair<int, int>;
using VPII = vector<PII>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

int n, ans = inf, best = -1;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		int ile = (n+i-1)/i;

		if(ans>i+ile)
		{
			ans = i+ile;
			best = i;
		}
	}

	cerr << ans << endl;

	for(int i = 1; i <= n; i += best)
	{
		for(int j = min(n, i+best-1); j >= i; --j)
		{
			cout << j << " ";
		}
	}
}