#include <bits/stdc++.h>
using namespace std;

#define N 20020

bool vis[N];

int a[111], b[111];
typedef pair <int, int> pii;
pii p[N];

int main() {
    for (int i = 0, k = 100; i < 100; i ++) {
        while (vis[k]) k ++;
        a[i] = i, b[i] = k;
        for (int i = 0; i < 100; i ++)
            for (int j = 0; j < 100; j ++) vis[i^j^k] = 1;
    }
    for (int i = 0; i < 100; i ++) for (int j = 0; j < 100; j ++) {
        int c = a[i] ^ b[j]; p[c] = pii(i, j);
    }
    int x, y;
    printf("?"); for (int i = 0; i < 100; i ++) printf(" %d", a[i]); puts(""); fflush(stdout); scanf("%d", &x);
    printf("?"); for (int i = 0; i < 100; i ++) printf(" %d", b[i]); puts(""); fflush(stdout); scanf("%d", &y);
    printf("! %d\n", x ^ p[x^y].first); fflush(stdout);
}