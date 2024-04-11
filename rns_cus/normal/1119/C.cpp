#include <bits/stdc++.h>
using namespace std;

#define N 555

int n, m, a[N][N], b[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++) scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++) scanf("%d", &b[i][j]);
    for (int i = 0; i < n; i ++) {
        int r = 0;
        for (int j = 0; j < m; j ++) r ^= a[i][j];
        for (int j = 0; j < m; j ++) r ^= b[i][j];
        if (r) return puts("No"), 0;
    }
    for (int i = 0; i < m; i ++) {
        int r = 0;
        for (int j = 0; j < n; j ++) r ^= a[j][i];
        for (int j = 0; j < n; j ++) r ^= b[j][i];
        if (r) return puts("No"), 0;
    }
    puts("Yes");
}