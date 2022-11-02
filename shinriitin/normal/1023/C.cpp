#include <bits/stdc++.h>

const int max_N = (int) 2e5 + 21;

int n, k, st[max_N], top;

char s[max_N], t[max_N];

int main() {
    scanf("%d%d%s", &n, &k, s);
    if (n == k) return puts(s), 0;
    int cnt = (n - k) / 2;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') ++top;
        else {
            --top;
            if (--cnt == 0) {
                for (int j = 0; j < top; ++j) t[j] = '(';
                for (int j = i + 1; j < n; ++j) t[top++] = s[j];
                t[top] = '\0';
                return puts(t), 0;
            }
        }
    }
    return 0;
}