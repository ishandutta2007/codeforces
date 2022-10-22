#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        map<int, int> cnt;
        vector<vector<int>> rcnt(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]] += 1;
        }
        set<pii> invalid;
        while(q--) {
            int x, y;
            cin >> x >> y;
            invalid.insert(pii(x, y));
            invalid.insert(pii(y, x));
        }
        auto ok = [&](int x, int y) {
            if (x > y) swap(x, y);
            if (invalid.find(pii(x, y)) == invalid.end()) {
                return true;
            } else {
                return false;
            }
        };
        for (auto &t : cnt) {
            rcnt[t.second].push_back(t.first);
        }
        vector<int> valid_cnt;
        for (int i = 0; i < n; i++) {
            if (rcnt[i].size() > 0) {
                valid_cnt.push_back(i);
            }
        }
        LL ans = 0;
        int m = valid_cnt.size();
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                vector<int> v1, v2;
                int cnt1 = valid_cnt[i]; 
                int cnt2 = valid_cnt[j];
                for (auto &t : rcnt[cnt1]) v1.push_back(t);
                for (auto &t : rcnt[cnt2]) v2.push_back(t);
                sort(v1.begin(), v1.end());
                sort(v2.begin(), v2.end());
                reverse(v1.begin(), v1.end());
                reverse(v2.begin(), v2.end());
                set<pii> vis;
                auto visited = [&](int x, int y) {
                    return vis.find(pii(x, y)) != vis.end();
                };
                priority_queue<pip> hp;
                vis.emplace(0, 0);
                hp.emplace(pip(v1[0] + v2[0], pii(0, 0)));
                while(!hp.empty()) {
                    auto now = hp.top();
                    hp.pop();
                    int val = now.first;
                    int n1 = now.second.first;
                    int n2 = now.second.second;
                    int r1 = v1[n1];
                    int r2 = v2[n2];
                    if (ok(r1, r2)) {
                        if (i != j || n1 != n2) {
                            ans = max(ans, 1LL * (r1 + r2) * (cnt1 + cnt2));
                            break;
                        }
                    }
                    if (n1 + 1 < v1.size() && !visited(n1 + 1, n2)) {
                        if (i != j || n1 + 1 <= n2) {
                            vis.emplace(n1 + 1, n2);
                            hp.push(pip(v1[n1 + 1] + v2[n2], pii(n1 + 1, n2)));
                        }
                    }
                    if (n2 + 1 < v2.size() && !visited(n1, n2 + 1)) {
                        if (i != j || n1 <= n2 + 1) {
                            vis.emplace(n1, n2 + 1);
                            hp.push(pip(v1[n1] + v2[n2 + 1], pii(n1, n2 + 1)));
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}