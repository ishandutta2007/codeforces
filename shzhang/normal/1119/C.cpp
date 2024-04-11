#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

int n, m;
int a[505][505];
int b[505][505];
int c[505][505];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &(a[i][j]));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &(b[i][j]));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            c[i][j] = a[i][j] ^ b[i][j];
        }
    }
    bool ans = true;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            cnt += c[i][j];
        }
        if (cnt % 2) ans = false;
    }
    for (int j = 1; j <= m; j++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += c[i][j];
        }
        if (cnt % 2) ans = false;
    }
    printf(ans ? "Yes" : "No");
    return 0;
}