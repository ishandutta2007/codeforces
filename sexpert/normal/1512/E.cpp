#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int sz = r - l + 1, mx = n - sz;
    s -= sz * (sz + 1)/2;
    if(s < 0) {
        cout << "-1\n";
        return;
    }
    vector<int> ans(n + 1);
    for(int i = l; i <= r; i++)
        ans[i] = i - l + 1;
    for(int i = r; i >= l; i--) {
        int x = min(s, mx);
        ans[i] += x;
        s -= x;
    }
    if(s != 0) {
        cout << "-1\n";
        return;
    }
    set<int> guys;
    for(int i = l; i <= r; i++)
        guys.insert(ans[i]);

    for(int i = 1, p = 1; i <= n; i++) {
        if(i >= l && i <= r)
            continue;
        while(guys.count(p))
            p++;
        ans[i] = p++;
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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