#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> pr;
    int copyn = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            pr.push_back({i, 0});
            while (n % i == 0) {
                pr.back().second++;
                n /= i;
            }
        }
    }
    if (n > 1) pr.push_back({n, 1});
    n = copyn;
    vector<int> d;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i != 1) d.push_back(i);
            if (n / i != i && n / i != 1) d.push_back(n / i);
        }
    }
    if (pr.size() == 1) {
        for (auto elem : d) cout << elem << " ";
        cout << "\n0\n";
        return;
    }
    if (pr.size() == 2 && pr[0].second == 1 && pr[1].second == 1) {
        for (auto elem : d) cout << elem << " ";
        cout << "\n1\n";
        return;
    }
    if (pr.size() == 2) {
        vector<int> good, only1, only2;
        for (auto elem : d) {
            bool f1 = elem % pr[0].first == 0;
            bool f2 = elem % pr[1].first == 0;
            if (f1 && f2) good.push_back(elem); else {
                if (f1) only1.push_back(elem); else only2.push_back(elem);
            }
        }
        for (auto elem : only1) cout << elem << " ";
        for (int i = 0; i + 1 < good.size(); ++i) cout << good[i] << " ";
        for (auto elem : only2) cout << elem << " ";
        cout << good.back();
        cout << "\n0\n";
        return;
    }
    set<int> rest;
    for (auto elem : d) rest.insert(elem);
    for (int i = 0; i < pr.size(); ++i) rest.erase(pr[i].first * pr[(i + 1) % pr.size()].first);
    vector<vector<int>> ans(pr.size());
    for (auto elem : rest) {
        int mn = 0;
        while (elem % pr[mn].first != 0) ++mn;
        ans[mn].push_back(elem);
    }
    for (int i = 0; i < pr.size(); ++i) {
        for (auto elem : ans[i]) cout << elem << " ";
        cout << pr[i].first * pr[(i + 1) % pr.size()].first << " ";
    }
    cout << "\n0\n";
}

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}