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

int p, k;
bool vis[1000010];
ll ret;

ll mod_pow(ll x, ll k, ll m)
{
    ll res = 1;
    for (; k; x = x * x % m, k /= 2) if (k & 1) res = res * x % m;
    return res;
}


int main() {
    cin >> p >> k;

    if (k == 0) {
	cout << mod_pow(p, p - 1, MOD) << endl;
	return 0;
    }

    if (k == 1) {
	ret = p;
    } else ret = 1;

    for (int i = 1; i < p; ++i) {
	if (vis[i]) continue;

	int cur = i;
	int sz = 0;

	while (true) {
	    vis[cur] = 1;
	    ++sz;
	    int nx = (ll)cur * k % p;

	    if (nx == i) break;
	    cur = nx;
	}

	ll t = 0;

	if (mod_pow(k, sz, p) == 1) {
	    t = p;
	} else {
	    t = 1;
	}

	ret = ret * t % MOD;
    }

    cout << ret << endl;

    return 0;
}