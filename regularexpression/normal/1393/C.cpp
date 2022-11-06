#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> cnt(n);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            --a;
            cnt[a]++;
        }
        int L = 0, R = n;
        while (R - L > 1) {
            int M = (L + R) / 2;
            auto cur = cnt;
            vector<vector<int>> here(n);
            for (int i = 0; i < n; ++i)
                if (cur[i] > 0)
                    here[0].push_back(i);
            set<pair<int, int>> S;
            bool ok = 1;
            for (int i = 0; i < n; ++i) {
                for (auto id : here[i])
                    S.insert({-cur[id], id});
                if (S.empty()) {
                    ok = 0;
                    break;
                }
                int id = S.begin()->second;
                S.erase(S.begin());
                --cur[id];
                if (cur[id] > 0 && i + M + 1 < n)
                    here[i + M + 1].push_back(id);
            }
            if (ok)
                L = M;
            else
                R = M;
        }
        cout << L << '\n';
    }
    return 0;
}