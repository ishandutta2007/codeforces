#include <bits/stdc++.h>

int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            putchar(i + j & 1 ? 'B' : 'W');
        } putchar('\n');
    }
    return 0;
} //