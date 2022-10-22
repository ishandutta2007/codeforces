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
    for (; k; x = x * x % MOD, k /= 2) if (k & 1) res = res * x % MOD;
    return res;
}

ll fact[100010];
ll ifact[100010];
ll ac[100010];

ll comb(ll n, ll k)
{
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}

int n, k;
ll ret;
string s;

int main() {
    fact[0] = ifact[0] = 1;

    for (int i = 1; i < 100010; ++i) {
	fact[i] = fact[i-1] * i % MOD;
	ifact[i] = mod_pow(fact[i], MOD - 2);
    }

    cin >> n >> k >> s;

    rep(i, n - 1) {
	ll t = mod_pow(10, i) * comb(n - 2 - i, k - 1) % MOD;
	ac[i + 1] = t;
    }

    rep(i, n) ac[i + 1] = (ac[i + 1] + ac[i]) % MOD;

    rep(i, n) {
	int num = s[i] - '0';
	ll ad = (ac[n - 1 - i] + mod_pow(10, n - 1 - i) * comb(i, k)) * num % MOD;
	ret = (ret + ad) % MOD;
    }

    cout << ret << endl;

    return 0;
}