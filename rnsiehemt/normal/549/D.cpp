#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;

int Y, X;
char b[105][105];
int a[105][105];
int c[105][105];
int ops;

int main()
{
    scanf("%d%d", &Y, &X);
    for (int y = 0; y < Y; y++) scanf(" %s", b[y]);
    for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) a[y][x] = (b[y][x] == 'W' ? 1 : -1);
    for (int y = Y-1; y >= 0; y--) for (int x = X-1; x >= 0; x--) {
        int d = a[y][x] - c[y][x]; if (d) ops++;
        for (int p = 0; p <= y; p++) for (int q = 0; q <= x; q++) c[p][q] += d;
    }
    printf("%d\n", ops);
}