#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 2E5 + 10, MAXK = 2E3 + 10;
const ll MOD = 1E9 + 7;

int n, m, K, s;
vector<PII> a;
ll f[MAXK][22];

ll inv[MAXN];
ll fac[MAXN], facinv[MAXN];

ll modExp(ll e, ll n, ll m = MOD){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % m)
		if (n & 1)
			ret = ret * e % m;
	return ret;
}

void modInv(int n = MAXN, ll m = MOD){
	inv[0] = 0, inv[1] = 1;
	fac[0] = fac[1] = 1;
	facinv[0] = facinv[1] = 1;
	for (int i = 2; i < MAXN; ++i){
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
		fac[i] = fac[i - 1] * i % MOD;
		facinv[i] = facinv[i - 1] * inv[i] % MOD;
	}
}

ll C(int n, int m){
	return n < m || m < 0 ? 0 : fac[n] * facinv[m] % MOD * facinv[n - m] % MOD;
}

int main(){
	modInv();

	scanf("%d%d%d%d", &n, &m, &K, &s);
	a.resize(K);
	for (int i = 0; i < K; ++i)
		scanf("%d%d", &a[i].st, &a[i].nd);
	sort(a.begin(), a.end());
	if (!a.empty() && a[0] == PII(1, 1))
		s = s + 1 >> 1;
	else
		a.insert(a.begin(), PII(1, 1)), ++K;
	if (a.size() > 1 && a[K - 1] == PII(n, m))
		a.pop_back(), --K, s = s + 1 >> 1;

	vector<int> b;
	for (; s > 1; s = s + 1 >> 1)
		b.push_back(s);
	b.push_back(1);
	int len = b.size();

	ll ans = C(n + m - 2, n - 1);
	for (int l = 0; l < len; ++l){
		for (int i = K - 1; i >= 0; --i){
			f[i][l] = C(n + m - a[i].st - a[i].nd, n - a[i].st);
			for (int j = i + 1; j < K; ++j)
				if (a[i].st <= a[j].st && a[i].nd <= a[j].nd)
					f[i][l] = (f[i][l] - f[j][l] * C(a[j].st + a[j].nd - a[i].st - a[i].nd, a[j].st - a[i].st)) % MOD;
			for (int j = 0; j < l; ++j)
				f[i][l] = (f[i][l] - f[i][j] + MOD) % MOD;
		}
		ans = (ans + f[0][l] * (b[l] - 1)) % MOD;
	}
	ans = ans * modExp(C(n + m - 2, n - 1), MOD - 2, MOD) % MOD;
	printf("%d\n", (int)ans);
	return 0;
}