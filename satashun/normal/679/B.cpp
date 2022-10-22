#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vp;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

short dp[31000010];
set<ll> u;
int r[31000010];

ll ans[] = {0, 1, 2, 3, 4, 5, 6, 7, 15, 23, 50, 114, 330, 1330, 10591, 215970, 19464802, 16542386125, 409477218238718};

ll ret;
int num;
ll m;

int main() {
    for (ll i = 1; i <= 1000; ++i) u.insert(i * i * i);

    for (int i = 1; i <= 31000000; ++i) {
	auto it = u.upper_bound(i);
	--it;

	dp[i] = dp[i - *it] + 1;
    }

    cin >> m;
    for (int i = 18; i >= 0; --i) {
	if (ans[i] <= m) {
	    num = i;
	    break;
	}
    }

    if (m == 1) {
	ret = 1;
    } else {

	r[0] = -1;
	rep(i, 31000000) {
	    r[i + 1] = r[i];
	    if ((int)dp[i] == num - 2) r[i + 1] = i;
	}

	for (ll i = 100000; i >= 1; --i) { //first
	    if (i * i * i > m) continue;

	    for (ll j = 3200; j >= 1; --j) {
		ll k = i * i * i + j * j * j;

		if (k > m) continue;
		if (k > (i + 1) * (i + 1) * (i + 1)) continue;

		ll ub = min((i + 1) * (i + 1) * (i + 1) - k, (j + 1) * (j + 1) * (j + 1) - j * j * j);
		ub = min(ub, m - k + 1);

		ll t = r[ub];
		if (t != -1) { 
		    ret = k + t;
		    goto EN;
		    ret = max(ret, k + t);
		}
	    }
	}

	EN:;
    }
    cout << num << " " << ret << endl;

    return 0;
}