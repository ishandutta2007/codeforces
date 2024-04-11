#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fdiv(ll a, ll b) {
    ll res = a + b, x = abs(res);
    if(res >= 0)
        return x/2;
    return -((x + 1)/2);
}

int n;
ll k;
vector<ll> v, tmp;

bool good(ll bnd) {
    auto f = [](ll x) -> ll { return 3LL*x*x + 3LL*x + 1; };
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        ll lo = 0, hi = v[i] - 1;
        if(v[i] - 1 < bnd) {
            tmp[i] = 0;
            continue;
        }
        while(lo < hi) {
            ll mi = (lo + hi + 1)/2;
            if(v[i] - f(mi) >= bnd)
                lo = mi;
            else
                hi = mi - 1;
        }
        tmp[i] = lo + 1;
        tot += lo + 1;
    }
    //cout << endl;
    //cout << tot << " " << k << endl;
    return (tot < k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    v.resize(n);
    tmp.resize(n);
    for(auto &x : v)
        cin >> x;

    ll lo = -4e18, hi = 1e9 + 10;
    while(lo < hi) {
        ll mi = fdiv(lo, hi);
        //cout << lo << " " << hi << endl;
        if(good(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    good(lo);
    lo--;
    ll su = accumulate(tmp.begin(), tmp.end(), 0LL);
    for(int i = 0; i < n; i++) {
        ll x = tmp[i];
        if(su < k && v[i] - 3LL*x*x - 3LL*x - 1 == lo && tmp[i] < v[i]) {
            su++;
            tmp[i]++;
        }
    }
    for(int i = 0; i < n; i++)
        cout << tmp[i] << " ";
    cout << '\n';
    //cout << lo << endl;
}