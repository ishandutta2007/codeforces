#include <bits/stdc++.h>
using namespace std;

#define N 300300

int n, a[N];
int vis[1<<20][2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), a[i] ^= a[i-1];
    for (int i = 0; i <= n; i ++) vis[a[i]][i%2] ++;
    long long rlt = 0;
    for (int i = 0; i < 1 << 20; i ++)
        for (int j = 0; j < 2; j ++)
            rlt += 1ll * vis[i][j] * (vis[i][j] - 1) / 2;
    cout << rlt << endl;

    return 0;
}