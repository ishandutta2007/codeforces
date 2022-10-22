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

ll mod_pow(ll x, ll n)
{
    ll res = 1;
    for (; n > 0; n /= 2, x = x * x % MOD) if (n & 1) res = res * x % MOD;
    return res;
}

int k;
ll a[100010];
ll p, q;
bool pari;

int main() {
    cin >> k;
    rep(i, k) cin >> a[i];

    ll t;

    rep(i, k) {
	if (i == 0) t = mod_pow(2, a[i]);
	else t = mod_pow(t, a[i]);
	pari |= (a[i] % 2 == 0);
    }

    pari ^= 1;

    t = t * mod_pow(2, MOD - 2) % MOD;
    
    q = t;
    p = (t + (pari ? -1 : 1));

    if (p < 0) p += MOD;
    p = p * mod_pow(3, MOD - 2) % MOD;

    cout << p << "/" << q << endl;

    return 0;
}