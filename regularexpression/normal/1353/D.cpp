#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second - a.first > b.second - b.first || (a.second - a.first == b.second - b.first && a.first < b.first);
}


void go(int l, int r) {
    if (l > r) return;
    v.emplace_back(l, r);
    int mid = (l + r) / 2;
    go(l, mid - 1);
    go(mid + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        v.clear();
        go(0, n - 1);
        sort(v.begin(), v.end(), cmp);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[(v[i].first + v[i].second) / 2] = i + 1;
        for (auto x : ans) cout << x << " ";
    }
    return 0;
}