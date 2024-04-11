#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v;
ll k;

bool can(ll n) {
    ll co = n*(n + 1)/2;
    if(co > k / v[0])
        return true;
    if(co*v[0] + (ll)n*v[1] + v[2] >= k)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll ans = 0;
    cin >> n >> k;
    v.assign(n, 0);
    for(auto &x : v)
        cin >> x;
    if(*max_element(v.begin(), v.end()) >= k) {
        cout << "0\n";
        return 0;
    }
    vector<ll> tv(n);
    partial_sum(v.begin(), v.end(), tv.begin());
    v = tv;
    ans++;
    reverse(v.begin(), v.end());
    while(v.back() == 0)
        v.pop_back();
    reverse(v.begin(), v.end());
    tv = v;
    if(v.size() >= 4) {
        while(*max_element(v.begin(), v.end()) < k) {
            ans++;
            partial_sum(v.begin(), v.end(), tv.begin());
            v = tv;
        }
        cout << ans << '\n';
        return 0;
    }
    if(v.size() == 2) {
        //ans*a + b >= k
        //ans >= (k - b)/a
        ans = (k - v[1] + v[0] - 1)/v[0];
        cout << ans + 1 << '\n';
        return 0;
    }
    //n*(n + 1)/2*v[0] + n*v[1] + v[2]
    ll lo = 1, hi = 2000000000;
    while(lo < hi) {
        ll mi = (lo + hi)/2;
        if(can(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    cout << lo + 1 << '\n';
}