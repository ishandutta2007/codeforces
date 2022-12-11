#include <bits/stdc++.h>

using namespace std;

bool solve() {
    int n, d; scanf("%d %d", &n, &d);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    sort(begin(arr), end(arr));
    if (all_of(begin(arr), end(arr), [&] (int i) {return i <= d;})) return true;
    return (arr[0] + arr[1]) <= d;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%s\n", solve() ? "YES" : "NO");
    return 0;
}