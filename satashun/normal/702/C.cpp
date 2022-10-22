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

int n, m;
vector<ll> v1, v2;

int imo[100010];

bool ok(ll r)
{
    for (ll m : v1) {//[m-r,m+r]
	auto it = lower_bound(ALL(v2), m - r);
	if (it == v2.end() || *it > m + r) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;

    rep(i, n) {
	int x;
	cin >> x;
	v1.pb(x);
    }

    rep(i, m) {
	int x;
	cin >> x;
	v2.pb(x);
    }

    ll lb = 0, ub = INT_MAX;

    if (ok(0)) ub = 0;

    while (ub - lb > 1) {
	ll m = (lb + ub) / 2;
	if (ok(m)) ub = m;
	else lb = m;
    }

    cout << ub << endl;
    return 0;
}