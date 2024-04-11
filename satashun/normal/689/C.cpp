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

ll m;

ll calc(ll x)
{
    ll r = 0;

    for (ll i = 2; i * i * i <= x; ++i) {
	r += max(x / (i * i * i), 0LL);
    }

    return r;
}

int main() {
    cin >> m;
    ll lo = 1, hi = 2e17;

    while (hi - lo > 1) {
	ll mid = (lo + hi) / 2;
	if (calc(mid) < m) lo = mid;
	else hi = mid;
    }
/*
    cout << calc(hi) << endl;
    cout << calc(lo) << endl;
*/
    if (calc(hi) == m) {
	cout << hi << endl;
    } else {
	cout << "-1\n";
    }

    return 0;
}