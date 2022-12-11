#include <cstdio>
const long long N = 2002;
int a[N][N], n, x1, y1, x2, y2;
long long d1[2 * N], d2[2 * N];
long long bst1 = -1, bst2 = -1, cur;

void relax1(int x, int y) {
    cur = d1[x + y];
    cur += d2[x - y + N];
    cur -= a[x][y];
    if (bst1 < cur) {
        bst1 = cur;
        x1 = x + 1;
        y1 = y + 1;
    }
}

void relax2(int x, int y) {
    cur = d1[x + y];
    cur += d2[x - y + N];
    cur -= a[x][y];
    if (bst2 < cur) {
        bst2 = cur;
        x2 = x + 1;
        y2 = y + 1;
    }
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            d1[i + j] += a[i][j];
            d2[i - j + N] += a[i][j];
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2)
                relax1(i, j);
            else
                relax2(i, j);
        }
    printf("%I64d\n", bst1 + bst2);
    printf("%d %d %d %d", x1, y1, x2, y2);
}