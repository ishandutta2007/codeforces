#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, xo = 0;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
        xo ^= x;
    }
    if(xo == 0) {
        cout << "YES\n";
        return;
    }
    int pf = 0, sf = 0, cur = 0;
    for(int i = 0; i < n; i++) {
        cur ^= v[i];
        if(cur == xo) {
            pf = i;
            break;
        }
    }
    cur = 0;
    for(int i = n - 1; i >= 0; i--) {
        cur ^= v[i];
        if(cur == xo) {
            sf = i;
            break;
        }
    }
    cout << ((pf < sf) ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();   
}