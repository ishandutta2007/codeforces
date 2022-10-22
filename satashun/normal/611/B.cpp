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

const ll BD = 1e18;
vector<ll> ok;

ll l, r;

void gen() 
{
    for (int len = 2; ; ++len) {
	ll t = (1LL << len) - 1;
	bool fd = 0;
	rep(i, len-1) {
	    ll nt = t - (1LL << i);
	    if (nt <= BD) fd = 1;
	    ok.pb(nt);
	}
	if (!fd) return ;
    }
}

int calc(ll x)
{
    return (upper_bound(ALL(ok), x) - ok.begin());
}

int main() {
    cin >> l >> r;
    gen();
    sort(ALL(ok));
    cout << calc(r) - calc(l-1) << endl;
    return 0;
}