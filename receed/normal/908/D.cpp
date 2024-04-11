#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;
ll dp[1002][2002];

ll pw(ll x, ll p) {
	if (p == 0)
		return 1;
	if (p % 2)
		return pw(x, p - 1) * x % mod;
	return pw(x * x % mod, p / 2);
}

ll diiv(ll x, ll y) {
	return x % mod * pw(y, mod - 2) % mod;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll k, pa, pb;
	cin >> k >> pa >> pb;
	for (ll i = 0; i < k; i++)
		dp[k][i] = i + k - 1 + diiv(pa + pb, pb);
	for (int i = k - 1; i > 0; i--)
		for (int j = k - 1; j >= 0; j--) {
			dp[i][j] = diiv(pa * dp[i + 1][j] + pb * (i + j >= k ? i + j : dp[i][i + j]), pa + pb);
		}
	cout << dp[1][0];
}