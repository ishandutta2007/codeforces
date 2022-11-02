#include <bits/stdc++.h>
using namespace std;

#define N 300300

int n;
char s[N];

int main() {
    scanf("%d %s", &n, s);
    long long ans = 1ll * n * (n - 1) / 2;
    for (int i = 1; i < n; i ++) if (s[i] != s[i-1]) ans --;
    for (int i = 0, j; i < n; ) {
        for (j = i + 1; j < n && s[j] != s[i]; j ++);
        if (j > i + 2) ans -= j - i - 2, i = j - 1;
        else i ++;
    }
    reverse(s, s + n);
    for (int i = 0, j; i < n; ) {
        for (j = i + 1; j < n && s[j] != s[i]; j ++);
        if (j > i + 2) ans -= j - i - 2, i = j - 1;
        else i ++;
    }
    printf("%lld\n", ans);
}