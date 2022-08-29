#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

inline void R(int &x) {
    char ch = getchar(); x = 0;
    for (; ch<'0'; ch = getchar());
    for (; ch>='0'; ch=getchar()) x = x*10 + ch-'0';
}
const int N = 1005, inf = (1<<30)-1, dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
int n, m;
char a[N][N], nxt[300];
bool v[N][N];
int f[N][N];
int dfs(int x, int y) {
    if (f[x][y]) return f[x][y];
    if (v[x][y]) return inf;
    v[x][y] = 1;
    int tx, ty, ans = 0;
    for (int i=0; i<4; ++i) {
        tx = x + dx[i], ty = y + dy[i];
        if (tx<1 || tx>n || ty<1 || ty>m) continue;
        if (a[tx][ty] == nxt[a[x][y]])
            ans = max(ans, dfs(tx, ty));
    }
    v[x][y] = 0;
    return f[x][y] = ans+1;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; ++i)
        scanf("%s", a[i]+1);
    nxt['D'] = 'I', nxt['I'] = 'M', nxt['M'] = 'A', nxt['A'] = 'D';
    int ans = 0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            if (a[i][j] == 'D')
                ans = max(ans, dfs(i, j));
    if (ans >= inf)
        puts("Poor Inna!");
    else {
        ans /= 4;
        if (!ans)
            puts("Poor Dima!"); else
            printf("%d\n", ans);
    }
    return 0;
}