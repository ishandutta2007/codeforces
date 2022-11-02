#include <bits/stdc++.h>
using namespace std;

int cnt[111];

int main() {
    int n, m;
    cin >> n >> m;
    bool fg = 0;
    for (int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        cnt[l]++;
        cnt[r + 1]--;
    }
    for (int i = 1; i <= m; i ++)
        cnt[i] += cnt[i - 1];
    vector <int> ans;
    for (int i = 1; i <= m; i ++) {
        if (!cnt[i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}