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

bool isprm(ll x)
{
    for (ll i = 2; i * i <= x; ++i) {
	if (x % i == 0) return false;
    }

    return true;
}

ll A;
bool prm[2000010];
vector<ll> vec;
vector<ll> divs[100010];
vector<int> ids;
vector<ll> dv;

int main() {
    cin >> A;

    for (ll i = 1; i * i <= A; ++i) {
	if (A % i == 0) {
	    dv.pb(i);
	    if (i * i != A) dv.pb(A / i);
	}
    }

    sort(ALL(dv));

    int now = 0;

    for (int i = 2; i <= 1000000; ++i) {
	if (!prm[i]) {
	    int id = vec.size();
	    vec.pb(i);

	    ll cur = i;
	    bool flg = 0;

	    while (1 + cur <= A) {
		if (A % (1 + cur) == 0) {
		    divs[now].pb(cur + 1);
		    flg = 1;
		}
		cur *= i;
	    }

	    if (flg) {
		ids.pb(id);
		++now;
	    }

	    for (int j = i * 2; j <= 1000000; j += i) {
		prm[j] = 1;
	    }
	}
    }

    vector<vector<ll>> dp(now + 1, vector<ll>((int)dv.size()));

    dp[0][0] = 1;

    rep(i, now) {
	rep(j, dv.size()) {
	    dp[i + 1][j] = dp[i][j];
	}

	rep(j, dv.size()) {
	    rep(k, divs[i].size()) {
		if ((A / dv[j]) % divs[i][k] == 0) {
		    int nid = lower_bound(ALL(dv), dv[j] * divs[i][k]) - dv.begin();
		    dp[i + 1][nid] += dp[i][j];
		}
	    }
	}
    }

    ll ret = dp[now][(int)dv.size() - 1];

    rep(i, dv.size()) {
	ll rem = A / dv[i];
	if (rem > 1e6) {
	    if (isprm(rem - 1)) ret += dp[now][i];
	}
    }

    cout << ret << endl;

    return 0;
}