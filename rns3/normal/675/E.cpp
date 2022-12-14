#include <bits/stdc++.h>
using namespace std;
#define N 22
#define M 300001

int a[M], pos[N][M], f[N][M], lg[M];
long long ans[M];

int find(int x, int y) {
    int z = lg[y-x+1];
    if(f[z][x] > f[z][y-(1<<z)+1]) return pos[z][x];
    return pos[z][y-(1<<z)+1];
}


int main() {
    //freopen("b.in", "r", stdin);
    lg[1] = 0;
    for(int i = 2; i < M; i ++) lg[i] = lg[i/2] + 1;
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i ++) scanf("%d", &a[i]);
    a[n] = n + 1;
    for(int i = 1; i <= n; i ++) f[0][i] = a[i], pos[0][i] = i;
    for(int i = 1; i <= 20; i ++) {
        for(int j = 1; j <= n; j ++) {
            int k = j + (1 << (i - 1));
            if(k > n) continue;
            int x = f[i-1][j], y = f[i-1][k];
            if(x >= y) f[i][j] = x, pos[i][j] = pos[i-1][j];
            else f[i][j] = y, pos[i][j] = pos[i-1][k];
        }
    }
    ans[n] = 0;
    long long res = 0;
    for(int i =  n - 1; i ; i --) {
        int x = a[i];
        int y = find(i, x);
        ans[i] = y - i + ans[y] + (n - y) - (x - y);
        res += ans[i];
    }
    cout << res << endl;
}