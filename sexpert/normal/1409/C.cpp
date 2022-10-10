#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ans(n, 1000000000);
    for(int d = 1; d <= y - x; d++) {
        if((y - x) % d)
            continue;
        if((y - x)/d >= n)
            continue;
        int st = y - (n - 1) * d;
        while(st <= 0)
            st += d;
        vector<int> v(n);
        v[0] = st;
        for(int i = 1; i < n; i++)
            v[i] = v[i - 1] + d;
        if(v.back() < ans.back())
            ans = v;
    }
    for(auto &x : ans)
        cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}