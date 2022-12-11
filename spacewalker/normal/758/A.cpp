#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    int ans = 0;
    int fval = *max_element(begin(arr), end(arr));
    for (int i = 0; i < n; ++i) {
        ans += fval - arr[i];
    }
    printf("%d\n", ans);
    return 0;
}