#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    map<int, int> cvalMax;
    vector<int> pxor(n+1);
    vector<int> ans(n+1);
    for (int i = 0; i < n; ++i) pxor[i+1] = pxor[i] ^ arr[i];
    cvalMax[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (cvalMax.count(pxor[i]) == 0) ans[i] = ans[i-1];
        else ans[i] = max(ans[i-1], cvalMax[pxor[i]] + 1);
        cvalMax[pxor[i]] = max(cvalMax[pxor[i]], ans[i]); 
    }
    return n - ans.back();
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%d\n", solve());
    }
    return 0;
}