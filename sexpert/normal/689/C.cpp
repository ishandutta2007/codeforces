#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v;

ll amt(ll x) {
    ll res = 0;
    for(auto y : v)
        res += x / y;
    return res;
}

int main() {
    for(ll n = 2; n <= 1000000; n++)
        v.push_back(n*n*n);
    ll m;
    cin >> m;
    ll lo = 0, hi = 1e16;
    while(lo < hi) {
        ll mi = (lo + hi)/2;
        if(amt(mi) >= m)
            hi = mi;
        else
            lo = mi + 1;
    }
    if(amt(lo) == m)
        cout << lo << endl;
    else
        cout << -1 << endl;
}