#include <bits/stdc++.h>
using namespace std;
int n, m, cur, mn, mx;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        mn = 2e9;
        for (int j = 0; j < m; j++) {
            cin >> cur;
            mn = min(mn, cur);
        }
        mx = max(mx, mn);
    }
    cout << mx;
}