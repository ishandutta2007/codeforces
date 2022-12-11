
#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for (int &v : arr) scanf("%d", &v);
    if (n <= 2) return n;
    map<int, int> occs;
    for (int v : arr) ++occs[v];
    if (occs.size() > 2) return n;
    for (auto [e, v] : occs) if (v != n/2) return n;
    return n/2 + 1;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%d\n", solve());
}