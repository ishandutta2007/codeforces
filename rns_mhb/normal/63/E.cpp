#include <bits/stdc++.h>
using namespace std;
#define M 19
#define N (1 << M)
#define gc getchar

typedef unsigned int ui;

bool g[N];

int pw[M], nxt[3][M] = {
    {1, 2, -1, 4, 5, 6, -1, 8, 9, 10, 11, -1, 13, 14, 15, -1, 17, 18, -1},
    {4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, -1, 16, 17, 18, -1, -1, -1, -1},
    {3, 4, 5, 7, 8, 9, 10, -1, 12, 13, 14, 15, -1, 16, 17, 18, -1, -1, -1}
};

char c;

int main() {
    //freopen("1.in", "r", stdin);
    int i, j, k, l, t;
    pw[0] = 1;
    for (i = 1; i < M; i ++) pw[i] = 2 * pw[i-1];

    for (i = 0; i < N; i ++) {
        if (g[i]) continue;
        bitset <M> b(i);
        for (j = 0; j < 3; j ++) {
            for (k = 0; k < M; k ++) {
                t = i;
                for (l = k; l >= 0 && !b[l]; l = nxt[j][l])
                    t += pw[l], g[t] = 1;
            }
        }
    }

    t = i = 0;
    while ((c = gc()) > 0)
        if (c > 32) {
            if (c == 'O') t += pw[i];
            i ++;
        }

    if (g[t]) puts("Karlsson");
    else puts("Lillebror");

    return 0;
}