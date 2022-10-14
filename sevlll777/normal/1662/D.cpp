#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define endl '\n'
#define int long long
typedef long double ld;

void solve() {
    string u, v;
    cin >> u >> v;
    int n = u.size();
    int m = v.size();
    string neu, nev;
    int bu = 0, bv = 0;
    for (int i = 0; i < n; i+=1) {
        if (u[i] == 'B') {
            bu++;
            continue;
        }
        if (neu.empty()) {
            neu.pb(u[i]);
        } else {
            if (neu.back() == u[i]) {
                neu.pop_back();
            } else {
                neu.pb(u[i]);
            }
        }
    }
    for (int i = 0; i < m; i+=1) {
        if (v[i] == 'B') {
            bv++;
            continue;
        }
        if (nev.empty()) {
            nev.pb(v[i]);
        } else {
            if (nev.back() == v[i]) {
                nev.pop_back();
            } else {
                nev.pb(v[i]);
            }
        }
    }
    if (bu % 2 != bv % 2) {
        cout << "NO" << endl;
        return;
    }
    if (nev == neu) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}