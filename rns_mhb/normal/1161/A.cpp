#include<bits/stdc++.h>
using namespace std;

#define N 100010

bool vis[3][N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int ans = 3 * n - 2;
    for(int i = 1, x; i <= k; i ++) {
        scanf("%d", &x);
        if(!vis[0][x]) {
            vis[0][x] = 1;
            ans --;
        }
        if(!vis[1][x] && vis[0][x-1]) {
            vis[1][x] = 1;
            ans --;
        }
        if(!vis[2][x] && vis[0][x+1]) {
            vis[2][x] = 1;
            ans --;
        }
    }
    printf("%d\n", ans);
}