#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 1e18;
        for (int ep = -100; ep <= 100; ep++) {
            int mahmud = (int) floor(sqrt(n))+ep;
            if (mahmud>0) {
                ans=min(ans,mahmud-1+(n-1)/mahmud);
            }
        }
        cout << ans;
        cout << '\n';
    }

}