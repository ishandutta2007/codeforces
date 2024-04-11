#include <bits/stdc++.h>

using namespace std;

#define int int64_t

vector<vector<int>> sons;
vector<int> s;
int ans = 0;

void assign_s(int v, int p) {
    if (s[v] == -1) {
        int mn = 2e18;
        for (int to: sons[v]) {
            mn = min(mn, s[to]);
        }
        if (sons[v].size() == 0) {
            s[v] = s[p];
        } else {
            s[v] = mn;
        }
    }
    for (int to: sons[v]) {
        assign_s(to, v);
    }
}

void count_ans(int v, int p) {
    if (p != -1 && s[p] > s[v]) {
        cout << "-1\n";
        exit(0);
    }
    ans += s[v] - (p == -1 ? 0 : s[p]);
    for (int to: sons[v]) {
        count_ans(to, v);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    sons.resize(n);
    s.resize(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        sons[p].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    assign_s(0, -1);
    count_ans(0, -1);
    cout << ans << '\n';
}