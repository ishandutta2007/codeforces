#include <bits/stdc++.h>

const int max_N = 500 + 21;

int n, r, c;

char ans[max_N * 2], ans1[max_N], tmp[5];

bool ask(int r1, int c1, int r2, int c2) {
    printf("? %d %d %d %d\n", r1, c1, r2, c2);
    fflush(stdout);
    scanf("%s", tmp);
    return *tmp == 'Y';
}

int main() {
    scanf("%d", &n);
    int r1 = 1, c1 = 1, cnt = 0;
    while ((n - r1) + (n - c1) > (n - 1)) {
        if (ask(r1, c1 + 1, n, n)) {
            ans[cnt++] = 'R';
            ++c1;
        } else {
            ans[cnt++] = 'D';
            ++r1;
        }
    }
    int r2 = n, c2 = n, cnt1 = 0;
    while ((r2 - 1) + (c2 - 1) > (n - 1)) {
        if (ask(1, 1, r2 - 1, c2)) {
            ans1[cnt1++] = 'D';
            --r2;
        } else {
            ans1[cnt1++] = 'R';
            --c2;
        }
    }
    //assert(r1 == r2 && c1 == c2);
    for (int i = cnt1 - 1; ~i; --i) ans[cnt++] = ans1[i];
    ans[cnt] = '\0';
    printf("! %s\n", ans);
    return 0;
}