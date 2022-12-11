#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve() {
    ll c, d; scanf("%lld %lld", &c, &d);
    if ((c + d) % 2 == 1) return -1;
    int ans = 0;
    if ((c + d) != 0) ++ans;
    if ((c - d) != 0) ++ans;
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        printf("%d\n", solve());
    }
}