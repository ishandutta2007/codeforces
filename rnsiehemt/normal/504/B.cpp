#include <bits/stdc++.h>

int N;
int bit[270005];
int a[270005];
int b[270005];
int c[270005];

void up(int i, int a) {
    while (i <= N) {
        bit[i] += a;
        i += (i&-i);
    }
}

int qu(int i) {
    int s = 0;
    while (i) {
        s += bit[i];
        i -= (i&-i);
    }
    return s;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf ("%d", &a[i]);
    for (int i = 0; i < N; i++) scanf ("%d", &b[i]);
    
    for (int i = 1; i <= N; i++) up(i, 1);
    for (int i = 0; i < N; i++) {
        int tmp = qu(a[i]);
        up(a[i]+1, -1);
        a[i] = tmp;
    }

    for (int i = 1; i <= N; i++) up(i, 1);
    for (int i = 0; i < N; i++) {
        int tmp = qu(b[i]);
        up(b[i]+1, -1);
        b[i] = tmp;
    }

    int carry = 0;
    for (int i = N-1; i >= 0; i--) {
        int j = N-i;
        c[i] = (a[i]+b[i]+carry) % j;
        carry = (a[i]+b[i]+carry) / j;
    }

    for (int i = 1; i <= N; i++) up(i, 1);
    for (int i = 0; i < N; i++) {
        int cur = 0, pos = 0;
        for (int k = 18; k >= 0; k--)
            if (pos+(1<<k) <= N && cur + bit[pos+(1<<k)] <= c[i]) {
                cur += bit[pos+(1<<k)];
                pos += (1<<k);
            }
        up(pos+1, -1);
        c[i] = pos;
    }

    for (int i = 0; i < N; i++) printf("%d%c", c[i], " \n"[i == N-1]);
}