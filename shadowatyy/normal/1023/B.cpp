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

#define int ll

int n, k;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	int lx = 1;
	int rx = n;
	lx = max(lx, k-n);
	rx = min(rx, k-1);

	if(lx>rx)
		cout << 0 << endl;
	else
	{
		int ans = rx-lx+1;

		if(k%2==0 && k/2<=n)
			--ans;

		ans /= 2;
		cout << ans << endl;
	}
}