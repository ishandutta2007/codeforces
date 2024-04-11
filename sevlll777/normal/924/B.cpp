#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, u;
    cin >> n >> u;
    vector<int> E(n);
    for (int i = 0 ; i< n; i++) cin >> E[i];
    //1-(ej-ei)/(ek-ei);
    //min -> (ej- ei) / (ek - ei);
    int p0 = -1, q0 = 1;
    for (int i = 0; i < n; i++) {
        int ek = E[i]+u;
        int ind = upper_bound(all(E), ek) - E.begin();
        ind--;
        if (ind > i+1) {
            int p = E[ind] - E[i+1];
            int q = E[ind]-E[i];
            if (p0 == -1) {
                p0 = p;
                q0 = q;
            } else if (p*q0 >= p0*q) {
                p0 = p;
                q0 = q;
            }
        }
    }
    long double ans = 1.0 * (long double) p0 / (long double) q0;
    if (ans == -1) {
        cout << "-1\n";
    } else {
        cout << fixed << setprecision(35) << ans << '\n';
    }
}