#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 200*1000+5;

int n, q, rt[1<<19][5][5], ans[5], next[5];
char s[maxn];

void qu(int n, int nl, int nr, int ql, int qr) {
    if (ql <= nl && nr <= qr) {
        for (int y = 0; y < 5; y++) {
            next[y] = 1e9;
            for (int x = 0; x < 5; x++) {
                next[y] = std::min(next[y], ans[x] + rt[n][x][y]);
            }
        }
        for (int y = 0; y < 5; y++) {
            ans[y] = next[y];
        }
    } else {
        int nm = (nl+nr)/2;
        if (ql < nm) qu(n*2+1, nl, nm, ql, qr);
        if (nm < qr) qu(n*2+2, nm, nr, ql, qr);
    }
}

int main() {
    scanf("%d%d", &n, &q);
    scanf(" %s", s);
    for (int i = 0; i < n; i++) {
        int j = (1<<18)-1 + i;
        for (int x = 0; x < 5; x++) for (int y = 0; y < 5; y++) {
            if (x == y) rt[j][x][y] = 0;
            else rt[j][x][y] = 1e9;
        }
        if (s[i] == '2') {
            rt[j][0][0] = 1;
            rt[j][0][1] = 0;
        } else if (s[i] == '0') {
            rt[j][1][1] = 1;
            rt[j][1][2] = 0;
        } else if (s[i] == '1') {
            rt[j][2][2] = 1;
            rt[j][2][3] = 0;
        } else if (s[i] == '6') {
            rt[j][3][3] = 1;
            rt[j][4][4] = 1;
        } else if (s[i] == '7') {
            rt[j][3][3] = 1;
            rt[j][3][4] = 0;
        }
    }
    for (int j = (1<<18)-2; j >= 0; j--) {
        for (int x = 0; x < 5; x++) for (int y = 0; y < 5; y++) {
            rt[j][x][y] = 1e9;
            for (int z = 0; z < 5; z++) {
                rt[j][x][y] = std::min(rt[j][x][y], rt[j*2+1][x][z] + rt[j*2+2][z][y]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b; scanf("%d%d", &a, &b); a--;
        ans[0] = 0;
        std::fill(ans+1, ans+5, 1e9);
        qu(0, 0, 1<<18, a, b);
        if (ans[4] == 1e9) ans[4] = -1;
        printf("%d\n", ans[4]);
    }
}