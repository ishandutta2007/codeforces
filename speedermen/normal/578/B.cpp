#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1 << 18;

long long a[MaxN], suff[MaxN], pref[MaxN];
int n, k, x;

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 1; i <= n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        a[i] = tmp;
    }
    long long mul = 1, ans = 0;
    for (int i = 1; i <= k; ++i) {
        mul *= x;
    }
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] | a[i];
    }
    for (int i = n; i > 0; --i){
        suff[i] = suff[i + 1] | a[i];
    }
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, suff[i + 1] | pref[i - 1] | (a[i] * mul));
    }
    cout << ans << '\n';
    return 0;
}