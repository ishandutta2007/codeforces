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
	for (; k; k /= 2, x = x * x % MOD) 
		if (k & 1) res = res * x % MOD;
	return res;
}

int n;
int x[300010];
ll c[300010];
ll d[300010];

ll ret;
vector<int> vec[300010];

int main() {
	scanf("%d", &n);

	rep(i, n) {
		scanf("%d", &x[i]);

		for (int j = 2; j * j <= x[i]; ++j) {
			if (x[i] % j == 0) {
				int cnt = 0;
				while (x[i] % j == 0) {
					x[i] /= j;
					++cnt;
				}
				vec[j].pb(cnt);
			}
		}
		if (x[i] != 1) vec[x[i]].pb(1);
	}

	c[0] = 1;
	rep(i, n-1) c[i+1] = c[i] * (n-1-i) % MOD * mod_pow(i+1, MOD-2) % MOD;
	rep(i, n-1) d[i+1] = (d[i] + c[i]) % MOD;

	for (int i = 2; i <= 300000; ++i) {
		if ((int)vec[i].size() == 0) continue;

		sort(ALL(vec[i]));
		int zero = n - vec[i].size();

		rep(j, vec[i].size()) {
			int k = j + zero;
			ll t = (d[k] - d[n-1-k] + MOD) * vec[i][j] % MOD;
			ret = (ret + t) % MOD;
		}
	}

	printf("%d\n", ret);

	return 0;
}