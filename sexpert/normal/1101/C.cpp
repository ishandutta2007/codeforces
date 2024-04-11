#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    int t;
    cin >> t;
    while(t--) {
        vector<pair<ii, int>> segs;
        int n;
        cin >> n;
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            segs.emplace_back(ii{l, r}, i);
        }
        sort(segs.begin(), segs.end());
        int cur = 1, mx = segs[0].first.second;
        for(auto s : segs) {
            if(cur == 1 && s.first.first > mx)
                cur = 2;
            mx = max(mx, s.first.second);
            ans[s.second] = cur;
        }
        if(cur == 1) {
            cout << -1 << endl;
            continue;
        }
        for(int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}