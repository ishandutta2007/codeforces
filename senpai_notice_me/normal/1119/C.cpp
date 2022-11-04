#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500 + 5;

int n, m;
int a[MAXN][MAXN], b[MAXN][MAXN];

int row[MAXN], col[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> b[i][j];
    
    for (int i = 1; i <= n; ++i) {
        row[i] = 0;
        for (int j = 1; j <= m; ++j) if (a[i][j] != b[i][j])
            row[i] += 1;
        if (row[i] & 1) {
            puts("No"); exit(0);
        }
    }
    
    for (int j = 1; j <= m; ++j) {
        col[j] = 0;
        for (int i = 1; i <= n; ++i) if (a[i][j] != b[i][j])
            col[j] += 1;
        if (col[j] & 1) {
            puts("No"); exit(0);
        }
    }
    
    puts("Yes");
    
    return 0;
}