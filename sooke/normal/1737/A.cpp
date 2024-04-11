#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 205;

int n, k, c[28];
char s[N], t[N];
bool vis[N], used[28];

int main() {
    for (int T = read(); T; T--) {
        n = read(); k = read();
        scanf("%s", s + 1);
        for (int i = 0; i < 26; i++) { c[i] = 0; }
        for (int i = 1; i <= n; i++) {
            c[s[i] - 'a']++;
        }
        for (int i = 1; i <= k; i++) {
            t[i] = 'a';
        }
        for (int j = 0; j < 26 && j < n / k; j++) {   
            for (int i = 1; i <= k; i++) {
                if (t[i] - 'a' == j && c[j] >= i) { t[i]++; }
            }
        }
        t[k + 1] = '\0';
        printf("%s\n", t + 1);
    }
    return 0;
}