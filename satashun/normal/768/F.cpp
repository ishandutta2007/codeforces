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
	for (; k; k /= 2, x = x * x % MOD) {
		if (k & 1) {
			res = res * x % MOD;
		}
	}
	return res;
}

int f, w, h;
ll fact[200010], ifact[200010];

ll comb(int n, int k)
{
	if (n < 0 || k < 0 || k > n) return 0;
	return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}

ll calc_w(int num)
{
	if ((ll)w <= (ll)num * h) return 0;
	return comb(w - num * h - 1, num - 1);
}

int main() {
	cin >> f >> w >> h;

	if (w == 0) {
		puts("1");
		return 0;
	}

	if (f == 0) {
		puts(w > h ? "1" : "0");
		return 0;
	}

	fact[0] = 1;

	for (int i = 1; i <= 200000; ++i) {
		fact[i] = fact[i-1] * i % MOD;
	}

	ifact[200000] = mod_pow(fact[200000], MOD - 2);
	for (int i = 200000 - 1; i >= 0; --i) {
		ifact[i] = ifact[i+1] * (i+1) % MOD;
	}

	ll all = 0, good = 0;

	for (int k = 1; k <= 100000; ++k) {
		ll ad = comb(f-1, k-1) * comb(w-1, k) % MOD;
		ad = (ad + comb(w-1, k-1) * comb(f-1, k)) % MOD;
		ad = (ad + comb(w-1, k-1) * comb(f-1, k-1) * 2) % MOD;
		all = (all + ad) % MOD;

		ll g = comb(f-1, k-1) * calc_w(k+1) % MOD;
		g = (g + calc_w(k) * comb(f-1, k)) % MOD;
		g = (g + calc_w(k) * comb(f-1, k-1) * 2) % MOD;
		good = (good + g) % MOD;

	}

	cout << good * mod_pow(all, MOD-2) % MOD << endl;

	return 0;
}