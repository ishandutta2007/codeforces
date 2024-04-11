#include<algorithm>
#include<iostream>
#include<numeric>
#include<iomanip>
#include<cassert>
#include<chrono>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<set>
#include<map>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	ll ans = 1;
	for (ll i = 1; i <= n + m; ++i) {
		ans *= 2ll;
		ans %= mod;
	}
	cout << ans;
	return 0;
}