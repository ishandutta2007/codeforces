#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; scanf("%d %d", &n, &k);
    vector<int> ans(k);
    iota(begin(ans), end(ans), 1);
    reverse(end(ans) - (n - k + 1), end(ans));
    for (int x : ans) printf("%d ", x);
    printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
    return 0;
}