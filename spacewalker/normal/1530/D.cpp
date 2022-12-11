#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; scanf("%d", &n);
    vector<int> hiling(n);
    for (int i = 0; i < n; ++i) scanf("%d", &hiling[i]);
    for (int i = 0; i < n; ++i) --hiling[i];
    map<int, int> takeElem;
    for (int i = 0; i < n; ++i) takeElem[hiling[i]] = i;
    if (takeElem.size() == n) {
        printf("%d\n", n);
        for (int v : hiling) printf("%d ", v + 1);
        printf("\n");
    } else if (takeElem.size() == n - 1) {
        vector<int> unass;
        for (int i = 0; i < n; ++i) if (takeElem.count(i) == 0) unass.push_back(i);
        map<int, int> freq;
        for (int v : hiling) ++freq[v];
        int repeater = -1;
        for (auto [v, f] : freq) if (f == 2) repeater = v;
        vector<int> idxs, ans(n, -1);
        for (int i = 0; i < n; ++i) {
            if (hiling[i] != repeater) ans[i] = hiling[i];
            else idxs.push_back(i);
        }
        int toGrant = idxs[0], toIgnore = idxs[1];
        if (toIgnore == unass[0]) swap(toGrant, toIgnore);
        ans[toGrant] = repeater;
        ans[toIgnore] = unass[0];
        printf("%d\n", n - 1);
        for (int v : ans) printf("%d ", v + 1);
        printf("\n");
    } else {
        vector<int> ans(n, -1);
        for (auto [v, i] : takeElem) {
            ans[i] = v;
        }
        vector<int> unass, uidx;
        for (int i = 0; i < n; ++i) if (takeElem.count(i) == 0) unass.push_back(i);
        int uiptr = 0;
        for (int i = 0; i < n; ++i) {
            if (ans[i] == -1) {
                ans[i] = unass[uiptr++];
                uidx.push_back(i);
            }
        }
        for (int k = 0; k < uidx.size(); ++k) {
            if (ans[uidx[k]] == uidx[k]) {
                swap(ans[uidx[k]], ans[uidx[(k + 1) % uidx.size()]]);
            }
        }
        printf("%lu\n", takeElem.size());
        for (int v : ans) printf("%d ", v + 1);
        printf("\n");
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}