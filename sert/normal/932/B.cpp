#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
#else
#endif
}

const int N = (int)1e6 + 34;
int f[N];
int g[N];
int pref[N][10];

int main() {
    init();

    for (int i = 0; i < 10; i++) {
        f[i] = g[i] = i;
    }

    for (int i = 10; i < N; i++) {
        f[i] = f[i / 10] * (i % 10 == 0 ? 1 : i % 10);
        g[i] = g[f[i]];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++)
            pref[i][j] = pref[i - 1][j];
        pref[i][g[i]]++;
    }

    int q, l, r, k;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d", &l, &r, &k);
        l--;
        printf("%d\n", pref[r][k] - pref[l][k]);
    }

    return 0;
}