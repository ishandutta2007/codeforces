#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
LL dp[32][2][2];
int A = 0, B = 0;

LL dfs(int pos, int f1, int f2) {
    if (pos == -1) return 1;
    if (dp[pos][f1][f2] != -1) return dp[pos][f1][f2];
    
    dp[pos][f1][f2] = 0;
    for (int i = 0; i < 3; i ++) {
        int p1 = i & 1;
        int p2 = (i >> 1) & 1;
        bool ok1 = (f1 == 0) || (f1 == 1 && p1 <= ((A>>pos)&1));
        bool ok2 = (f2 == 0) || (f2 == 1 && p2 <= ((B>>pos)&1));
        if (ok1 && ok2) {
            dp[pos][f1][f2] += dfs(pos - 1, f1 && p1 == ((A>>pos)&1),  f2 && p2 == ((B>>pos)&1));
        }
    }
    //printf("dp[%d][%d][%d] = %d\n", pos, f1, f2, dp[pos][f1][f2]);
    return dp[pos][f1][f2];
}
LL solve(int x, int y) {
    if (x == -1 || y == -1) return 0;
    A = x, B = y;
    memset(dp, -1, sizeof(dp));
    return dfs(30,1,1);
}
LL cac(int l, int r) {
    LL ans = solve(r, r) + solve(l-1, l-1) - solve(l-1,r) - solve(r,l-1);
    return ans;
}
int t;
int main() {
    scanf("%d", &t);
    while (t --) {
        int x, y; scanf("%d%d", &x, &y);
        cout << cac(x, y) << endl;
    }
}