#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll GCD(ll x, ll y) {
    if (y == 0) {
        return x;
    }
    return GCD(y, x % y);
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#else
    //    freopen("lupa.in","r",stdin);
    //    freopen("pupa.out","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10);
    cout << fixed;
    int n;
    cin >> n;
    vector<vector<ll>> a;
    for (int i = 0; i < 2; ++i) {
        vector<ll> vals;
        for (int j = 0; j < 2; ++j) {
            int val;
            cin >> val;
            vals.push_back(val);
        }
        a.push_back(vals);
    }
    swap(a[0][1], a[1][0]);
    ll det = abs(a[0][0] * a[1][1] - a[1][0] * a[0][1]);
    if (det != n) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    ll gcd = GCD(abs(a[0][0]), abs(a[0][1]));
    ll ost = det / gcd;
    assert(det == gcd * ost);
//    if(det != n) {
//        cout <<
//    }
    for (int i = 0; i < gcd; ++i) {
        for (int j = 0; j < ost; ++j) {
            cout << i << " " << j << '\n';
        }
    }

    return 0;
}