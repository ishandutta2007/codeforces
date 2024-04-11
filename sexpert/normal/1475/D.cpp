#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; ll m, ans = 1e9;
    cin >> n >> m;
    vector<ll> a(n), g1, g2;
    for(auto &x : a)
        cin >> x;
    for(int i = 0; i < n; i++) {
        int b;
        cin >> b;
        if(b == 1)
            g1.push_back(a[i]);
        else
            g2.push_back(a[i]);
    }
    sort(g1.begin(), g1.end());
    sort(g2.rbegin(), g2.rend());
    /*cout << "GUYS\n";
    for(auto &x : g1)
        cout << x << " ";
    cout << '\n';
    for(auto &x : g2)
        cout << x << " ";
    cout << '\n';*/
    ll tot = 0, sum = 0, p = 0;
    for(auto &x : g1) {
        sum += x;
        tot++;
    }
    for(int i = 0; i <= g1.size(); i++) {
        while(sum < m && p < g2.size()) {
            sum += g2[p++];
            tot += 2;
        }
        if(sum >= m)
            ans = min(ans, tot);
        if(i < g1.size()) {
            tot--;
            sum -= g1[i];
        }
    }
    cout << ((ans < 1e7) ? ans : -1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}