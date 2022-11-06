#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 6e18;

inline ll pr(ll x, ll y)
{
    return (x - y) * (x - y);
}

ll fnc(vector <ll> a, vector <ll> b, vector <ll> c)
{
    ll ans = sz;
    for(ll x : a) {
        ll y = upper_bound(b.begin(), b.end(), x - 1) - b.begin();
        if(y == b.size()) break;
        y = b[y];

        ll zm = (x + y) >> 1;
        ll z1 = upper_bound(c.begin(), c.end(), zm - 1) - c.begin();
        if(z1 != c.size()) {
            ll z = c[z1];
            ll now = pr(x, y) + pr(y, z) + pr(z, x);
            ans = min(ans, now);
        }
        z1--;
        if(z1 >= 0) {
            ll z = c[z1];
            ll now = pr(x, y) + pr(y, z) + pr(z, x);
            ans = min(ans, now);
        }
    }
    return ans;
}

void solve()
{
    int na, nb, nc;
    scanf("%d %d %d", &na, &nb, &nc);
    vector <ll> a(na), b(nb), c(nc);
    for(int i=0; i<na; i++) scanf("%lld", &a[i]);
    for(int i=0; i<nb; i++) scanf("%lld", &b[i]);
    for(int i=0; i<nc; i++) scanf("%lld", &c[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = sz;
    ans = min(ans, fnc(a, b, c));
    ans = min(ans, fnc(a, c, b));
    ans = min(ans, fnc(b, c, a));
    ans = min(ans, fnc(b, a, c));
    ans = min(ans, fnc(c, a, b));
    ans = min(ans, fnc(c, b, a));

    printf("%lld\n", ans);
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}