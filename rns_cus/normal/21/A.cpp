#include <bits/stdc++.h>
using namespace std;

#define N 155

char s[N];

bool check_1(int l, int r) {
    if (l >= r || r - l > 16) return 0;
    for (int i = l; i < r; i ++) {
        if (!(isalnum(s[i]) || s[i] == '_')) return 0;
    }
    return 1;
}

bool check() {
    int k, n = strlen(s);
    for (k = 0; k < n && s[k] != '@'; k ++);
    if (k == n) return 0;
    if (!check_1(0, k)) return 0; k ++;
    if (k == n) return 0;
    for (int i = k, j = k; i < n; i = j) {
        while (j < n && s[j] != '.' && s[j] != '/') j ++;
        if (!check_1(i, j)) return 0;
        if (j == n - 1) return 0;
        if (s[j] == '/') {
            if (k >= j || j - k > 32) return 0;
            if (!check_1(j + 1, n)) return 0;
            return 1;
        }
        j ++;
    }
    return 1;
}

int main() {
    scanf("%s", s);
    puts(check() ? "YES" : "NO");

    return 0;
}