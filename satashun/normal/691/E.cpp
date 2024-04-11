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

int n;
ll num;
ll a[110];
ll way[110][110];
ll res[110][110];
ll t[110][110];
ll ret;

int main() {
    cin >> n >> num;
    rep(i, n) cin >> a[i];

    rep(i, n) rep(j, n) if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0) {
	way[i][j] = 1;
    }

    rep(i, n) res[i][i] = 1;

    --num;

    while (num) {
	if (num & 1) {
	    memset(t, 0, sizeof(t));
	    rep(k, n) rep(i, n) rep(j, n) {
		t[i][j] = (t[i][j] + res[i][k] * way[k][j]) % MOD;
	    }
	    rep(i, n) rep(j, n) res[i][j] = t[i][j];
	}

	memset(t, 0, sizeof(t));
	rep(k, n) rep(i, n) rep(j, n) {
	    t[i][j] = (t[i][j] + way[i][k] * way[k][j]) % MOD;
	}

	rep(i, n) rep(j, n) way[i][j] = t[i][j];

	num /= 2;
    }

    rep(i, n) rep(j, n) ret = (ret + res[i][j]) % MOD;
   
    cout << ret << endl;
    return 0;
}