#include <bits/stdc++.h>

const int max_N = (int) 1e5 + 21;

int n, cnt[26];

char s[max_N];

int main() {
    scanf("%d%s", &n, s);
    if (n == 1) return puts("Yes"), 0;
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';
        if (++cnt[c] >= 2) return puts("Yes"), 0;
    }
    return puts("No"), 0;
}