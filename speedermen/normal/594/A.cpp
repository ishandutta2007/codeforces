#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vector <int> x(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    sort(x.begin(), x.end());
    int ans = INT_MAX;
    for (int i = 0; i < n / 2; ++i) {
        ans = min(ans, x[i + n / 2] - x[i]);
    }
    cout << ans << '\n';
    return 0;
}