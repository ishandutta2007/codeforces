#include <bits\stdc++.h>

using namespace std;

#define ll long long

ll* a;
ll n;
ll bs(ll l, ll u, ll k) {
    ll mid = l + (u - l) / 2;
    if (mid == l) {
        if (a[l] + k > 0) {
            return l;
        } else if (a[u] + k > 0){
            return u;
        } else {
            return -1;
        }
    }

    if (a[mid] + k > 0) {
        return bs(l, mid, k);
    } else return bs(mid, u, k);
}

int main() {
    cin >> n;
    a = new ll[n];
    ll* b = new ll[n];

    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        a[i] = b[i] - k;
    }

    sort(a, a + n);
    ll s = 0;
    for (ll i = 0; i < n - 1; i++) {
        ll ind = bs(i + 1, n - 1, a[i]);
        if (ind != -1) s += n - ind;
    }

    cout << s << endl;
    return 0;
}