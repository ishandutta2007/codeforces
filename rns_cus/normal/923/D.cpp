#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, m, q;
int sum[N][2], prv[N][2];
char s[N], t[N];

int main() {
    scanf("%s %s", s + 1, t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1; i <= n; i ++) {
        sum[i][0] = sum[i-1][0];
        prv[i][0] = prv[i-1][0];
        if (s[i] == 'A') s[i] = 0;
        else s[i] = 1, sum[i][0] ++, prv[i][0] = i;
    }
    for (int i = 1; i <= m; i ++) {
        sum[i][1] = sum[i-1][1];
        prv[i][1] = prv[i-1][1];
        if (t[i] == 'A') t[i] = 0;
        else t[i] = 1, sum[i][1] ++, prv[i][1] = i;
    }
    scanf("%d", &q);
    while (q --) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int k = max(c - 1, prv[d][1]);
        assert(sum[d][1] == sum[k][1]);
        if (b - a < d - k - 1 || sum[b][0] != sum[b+k-d][0]) {putchar('0'); continue;}
        b += k - d; d = k;
        if (b == a - 1 && d >= c) {putchar('0'); continue;}
        int S = sum[b][0] - sum[a-1][0], T = sum[d][1] - sum[c-1][1];
        if ((b - max(a - 1, prv[b][0])) % 3) S += 2;
        if (S > T || S % 2 != T % 2) putchar('0');
        else putchar('1');
    }
}