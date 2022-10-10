#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll I;
    cin >> n >> I;
    I *= 8;
    ll k = min(25ll, I/n);
    if(n > I)
        k = 0;
    ll K = (1LL << k);
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    int l = 0, r = 0, distinct = 0;
    ll ans = 1000000000000000000LL;
    while(l < n) {
        while(r < n && (l == r || v[r] == v[r - 1] || distinct < K))  {
            if(l == r || v[r] != v[r - 1])
                distinct++;
            r++;
        }
        //cout << "[" << l << ", " << r << ") " << distinct << endl;
        ans = min(ans, (ll)(n - (r - l)));
        if(l < n - 1 && v[l] != v[l + 1])
            distinct--;
        l++;
    }
    cout << ans << endl;
}