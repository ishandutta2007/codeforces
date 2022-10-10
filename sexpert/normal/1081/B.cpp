#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt[100005], a[100005], ans[100005];
    vector<pair<int, int>> cs;
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        cs.push_back({n - a[i], i});
    }
    sort(cs.begin(), cs.end());
    for(int i = 0; i < n; i++) {
        if(cnt[i] % (n - i)) {
            cout << "Impossible\n";
            return 0;
        }
    }
    cout << "Possible\n";
    int idx = 0, col = 1;
    while(idx < n) {
        int u = cs[idx].first;
        for(int i = idx; i < idx + u; i++) {
            ans[cs[i].second] = col;
        }
        idx += u;
        col++;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
}