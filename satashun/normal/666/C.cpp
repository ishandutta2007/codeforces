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

int m;
string s;
ll m26[200010];
ll m25[200010];
ll inv[200010];
ll inv26[200010];

map<int, vector<int> > T; 

ll mod_pow(ll x, ll k)
{
    ll res = 1;
    for (; k; x = x * x % MOD, k /= 2) if (k & 1) res = res * x % MOD;
    return res;
}

ll md(ll &x)
{
    if (x >= MOD) x -= MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    m26[0] = inv26[0] = 1;
    m25[0] = 1;

    for (int i = 1; i <= 200000; ++i) {
	m26[i] = m26[i - 1] * 26 % MOD;
	m25[i] = m25[i - 1] * 25 % MOD;
	inv26[i] = mod_pow(m26[i], MOD - 2);
    }

    for (int i = 1; i <= 200000; ++i) inv[i] = mod_pow(i, MOD - 2);

    cin >> m >> s;

    int l = s.size();

    {
	vector<int> u(100010);
	ll c = 1, sm = 0;

	for (ll i = 0; i <= 100000; ++i) {
	    sm += m25[i] * inv26[i] % MOD * c % MOD;
	    md(sm);
	    u[i] = sm;
	    c = c * (i + l) % MOD * inv[i + 1] % MOD;
	}
	T[l] = u;
    }

    while (m--) {
	int t;
	cin >> t;

	if (t == 1) {
	    cin >> s;
	    l = s.size();
	    if (!T.count(l)) {
		vector<int> u(100010);
		ll c = 1, sm = 0;

		for (ll i = 0; i <= 100000; ++i) {
		    sm += m25[i] * inv26[i] % MOD * c % MOD;
		    md(sm);
		    u[i] = sm;
		    c = c * (i + l) % MOD * inv[i + 1] % MOD;
		}
		T[l] = u;
	    }
	} else {
	    int n;
	    cin >> n;

	    if (n < l) cout << "0\n";
	    else {
		int r = n - l;
		ll ret = m26[r] * T[l][r] % MOD;
		cout << ret << "\n";
	    }
	}
    }

    return 0;
}