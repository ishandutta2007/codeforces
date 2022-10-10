#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int INF = 1e9;
 
ll f(ll n) {
    return (n*(n - 1ll))/2ll;
}
 
int main() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.rbegin(), v.rend());
    ll sum = 0, ans = INF;
    for(ll i = 0; i < n; i++) {
        sum += v[i];
        if(sum < m)
            continue;
        ll lo = 1, hi = i + 1;
        while(lo < hi) {
            ll mi = (lo + hi)/2;
            ll d = (i + 1ll)/mi, ex = (i + 1ll)%mi;
            ll tot = sum - ex*f(d + 1) - (mi - ex)*f(d);
            //cout << i + 1 << " " << d << " " << " " << ex << " " << tot << endl;
            if(tot >= m)
                hi = mi;
            else
                lo = mi + 1;
        }
        ans = min(ans, lo);
    }
    cout << (ans == INF ? -1 : ans) << endl;
}