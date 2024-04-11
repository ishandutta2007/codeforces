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

int q;
map<ll, ll> cost;

ll lca(ll x, ll y)
{
    if (x > y) swap(x, y);

    int d1 = 0, d2 = 0;
    ll t;

    t = x;

    while (t != 1) {
	t /= 2;
	++d1;
    }

    t = y;
    while (t != 1) {
	t /= 2;
	++d2;
    }

    while (d2 > d1) {
	y /= 2;
	--d2;
    }

    while (x != y) {
	x /= 2;
	y /= 2;
    }
    return x;
}

int main() {
    cin >> q;
    while (q--) {
	int tp;

	ll v, u, w;
	cin >> tp >> v >> u;

	ll r = lca(v, u);

	if (tp == 1) {
	    cin >> w;
	    while (v != r) {
		cost[v] += w;
		v /= 2;
	    }
	    while (u != r) {
		cost[u] += w;
		u /= 2;
	    }
	} else {
	    ll ret = 0;
	    while (v != r) {
		ret += cost[v];
		v /= 2;
	    }
	    while (u != r) {
		ret += cost[u];
		u /= 2;
	    }
	    cout << ret << endl;
	}
    }

    return 0;
}