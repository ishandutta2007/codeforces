#include <bits/stdc++.h>
using namespace std;
#define M 3030
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int ABS(int u) {return u > 0 ? u : -u;}
const int mod = 1000000007;

int n, m;
char s[M][M];
int f[M][M];

int add(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

ll solve(int sx, int sy, int ex, int ey) {
    if (s[sx][sy] == '#' || s[ex][ey] == '#') {
        return 0;
    }
    memset(f, 0, sizeof f);
    f[sx][sy] = 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (i > 1 || j > 1) {
        if (s[i][j] == '#') {
            continue;
        }
        if (i > 1 && f[i-1][j]) {
            add(f[i][j], f[i-1][j]);
        }
        if (j > 1 && f[i][j-1]) {
            add(f[i][j], f[i][j-1]);
        }
    }
    return f[ex][ey];
}

int main() {
    //freopen("D2.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    if (s[1][1] == '#' || s[n][m] == '#') {
        puts("0");
        return 0;
    }
    ll x = solve(1, 2, n - 1, m);
    ll y = solve(2, 1, n, m - 1);
    ll xx = solve(1, 2, n, m - 1);
    ll yy = solve(2, 1, n - 1, m);
    ll rlt = (x * y - xx * yy) % mod;
    printf("%I64d\n", (rlt + mod) % mod);
    return 0;
}