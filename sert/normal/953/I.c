#include <stdio.h>

int main() {
    //freopen("a.in", "r", stdin);
    int n, i, t, h, m, j;
    int s[300];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d:%d\n", &h, &m);
        s[i] = h * 60 + m;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        s[i + n] = s[i] + 60 * 24;
    }

    int mx = 0, cur;
    for (int i = 0; i < n; i++) {
        cur = s[i + 1] - s[i] - 1;
        if (cur > mx) mx = cur;
    }

    printf("%02d:%02d\n", mx / 60, mx % 60);

    return 0;
}