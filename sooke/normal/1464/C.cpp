#include <bits/stdc++.h>

const int N = 1e6 + 5;

int n, f[N];
long long k;
char s[N];

bool check() {
    k -= 1 << (s[n] - 'a');
    k += 1 << (s[n - 1] - 'a');
    n -= 2;
    if (n == 0) { return k == 0; }
    for (int i = 1; i <= n; i++) {
        k += 1 << (s[i] - 'a'); f[s[i] - 'a']++;
    }
    if (k % 2 != 0) { return false; }
    k /= 2;
    for (int i = 25; i >= 0; i--) {
        for (; f[i]; f[i]--) {
            if (k - (1 << i) >= 0) { k -= 1 << i; }
        }
    }
    return k == 0;
}

int main() {
    scanf("%d%lld", &n, &k);
    scanf("%s", s + 1);
    printf("%s\n", check() ? "YES" : "NO");
    return 0;
}