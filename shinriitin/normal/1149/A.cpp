#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    int a, cnt[2] = {};
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++cnt[a - 1];
    }
    if (cnt[1]) {
        printf("2 ");
        --cnt[1];
    }
    if (cnt[0]) {
        printf("1 ");
        --cnt[0];
    }
    while (cnt[1]) {
        printf("2 ");
        --cnt[1];
    }
    while (cnt[0]) {
        printf("1 ");
        --cnt[0];
    }
    puts("");
}