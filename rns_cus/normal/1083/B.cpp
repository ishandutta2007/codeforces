#include <bits/stdc++.h>
using namespace std;

#define N 500500
int n, k;
char s[N], t[N];

int main() {
    scanf("%d %d", &n, &k);
    scanf("%s %s", s, t);
    long long ans = 0, cur = 1;
    for (int i = 0; i < n; i ++) {
        if (cur < k) {
            cur <<= 1;
            if (s[i] == 'b') cur --;
            if (t[i] == 'a') cur --;
        }
        ans += min(cur, 1ll * k);
    }
    printf("%lld\n", ans);
    return 0;
}