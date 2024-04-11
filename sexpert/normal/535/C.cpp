#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B, l, t, m;

bool check(ll r) {
    ll s = A*(r - l + 1) + B*(r*(r - 1)/2 - (l - 1)*(l - 2)/2);
    ll mx = A + (r - 1)*B;
    return (max(mx, (s + m - 1)/m) <= t);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> A >> B >> n;
    for(int i = 0; i < n; i++) {
        cin >> l >> t >> m;
        ll lo = l, hi = 1e7;
        while(lo < hi) {
            ll mi = (lo + hi + 1)/2;
            if(check(mi))
                lo = mi;
            else
                hi = mi - 1;
        }
        if(A + (l - 1)*B > t)
            cout << "-1\n";
        else
            cout << lo << '\n';
    }
}