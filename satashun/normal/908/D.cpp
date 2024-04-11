#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const ll MOD = 1000000007;

ll mod_pow(ll x, ll k)
{
	ll res = 1;
	for (; k; x = x * x % MOD, k /= 2) {
		if (k & 1) {
			res = res * x % MOD;
		}
	}
	return res;
}

int k;
ll ret;
ll pa, pb;
ll dp[1010][1010];

int main() {
	cin >> k >> pa >> pb;
	ll p1 = pa * mod_pow(pa + pb, MOD - 2) % MOD;
	ll p2 = pb * mod_pow(pa + pb, MOD - 2) % MOD;

	dp[0][1] = 1;

	rep(i, k) {
		for (int j = 1; j <= k; ++j) {
			if (i + j >= k) {
				ll t = pa * mod_pow(pb, MOD - 2) % MOD;
				ret = (ret + dp[i][j] * (i + j + t)) % MOD;
			} else {
				dp[i+j][j] = (dp[i+j][j] + dp[i][j] * p2) % MOD;
				dp[i][j+1] = (dp[i][j+1] + dp[i][j] * p1) % MOD;
			}
		}
	}

	cout << ret << endl;

	return 0;
}