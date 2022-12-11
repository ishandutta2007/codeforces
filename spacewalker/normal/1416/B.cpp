#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    vector<tuple<int, int, int>> ops;
    auto operate = [&] (int i, int j, int x) {
        ops.emplace_back(i, j, x);
        arr[i] -= (i+1) * x;
        arr[j] += (i+1) * x;
        assert(arr[i] >= 0);
        assert(arr[j] >= 0);
    };
    for (int i = 1; i < n; ++i) {
        int borrow = arr[i] % (i + 1);
        if (borrow != 0) borrow = (i + 1) - borrow;
        operate(0, i, borrow);
        operate(i, 0, arr[i] / (i + 1));
    }
    if (arr[0] % n != 0) {
        printf("-1\n");
    } else {
        int cval = arr[0] / n;
        for (int i = 1; i < n; ++i) operate(0, i, cval);
        printf("%lu\n", ops.size());
        for (auto [i, j, x] : ops) printf("%d %d %d\n", i + 1, j + 1, x);
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}