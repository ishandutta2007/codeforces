#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
ll n, ans;

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%I64d", &n);
        ans = 1;
        while (ans <= n) ans *= 2;
        ans = 2 * (1 - ans) + (n * (n + 1)) / 2;
        printf("%I64d\n", ans);
    }
}