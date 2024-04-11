#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<int> g[N];
int cnt[N], e[N];
set<int> st[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> e[i];
    while (m--) {
        int t1, t2;
        cin >> t1 >> t2;
        cnt[t1]++;
        g[t2].push_back(t1);
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) st[e[i]].insert(i);
    }
    int ans = 0;
    while (!st[0].empty() || !st[1].empty()) {
        while (!st[0].empty()) {
            int v = *st[0].begin();
            st[0].erase(st[0].begin());
            for (auto i : g[v]) {
                cnt[i]--;
                if (cnt[i] == 0) st[e[i]].insert(i);
            }
        }
        if (!st[1].empty()) ans++;
        while (!st[1].empty()) {
            int v = *st[1].begin();
            st[1].erase(st[1].begin());
            for (auto i : g[v]) {
                cnt[i]--;
                if (cnt[i] == 0) st[e[i]].insert(i);
            }
        }
    }
    cout << ans;
    return 0;
}