#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

int MOD = 1000000007;

int main() {
	ll r, g; cin >> r >> g;
	if (r > g) swap(r, g);
	ll h;
	for (h = 0; h * (h + 1) / 2 <= r + g; h++);
	h--;
	ll sum = h * (h + 1) / 2;
	ll x = min(r, sum), y = max(0LL, sum - g);
	vector<ll> dp(x + 1);
	dp[0] = 1;
	for (int i = 1; i <= h; i++)
		for (int j = x - i; j >= 0; j--)
			dp[j + i] = (dp[j + i] + dp[j]) % MOD;
	ll ans = 0;
	for (int j = y; j <= x; j++)
		ans = (ans + dp[j]) % MOD;
	cout << ans << endl;
}