#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 511;
const long double EPS = 1e-12;

int n, m, r1, r2, c1, c2;
char a[N][N];
bool u[N][N];

bool dfs(int y, int x) {
    if (y == r2 && x == c2)
        return true;
    if (a[y][x] == 'X' && (y != r1 || x != c1))
        return false;
    if (u[y][x])
        return false;
    u[y][x] = true;
    bool ans = false;
    ans |= dfs(y - 1, x);
    ans |= dfs(y + 1, x);
    ans |= dfs(y, x + 1);
    ans |= dfs(y, x - 1);
    return ans;
}

int q(int y, int x) {
    return (a[y][x] == '.' ? 1 : 0);
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    scanf("%d%d ", &n, &m);
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            if (i == 0 || j == 0 || i > n || j > m)
                a[i][j] = 'X';
            else
                scanf("%c ", &a[i][j]);
    scanf("%d%d%d%d ", &r1, &c1, &r2, &c2);
    int qq = q(r2 - 1, c2) + q(r2 + 1, c2) + q(r2, c2 - 1) + q(r2, c2 + 1);
    if (r2 == r1 && c2 == c1 && qq < 1) {
        cout << "NO\n";
        return 0;
    }
    if (r1 == r2 && c1 == c2) {
        cout << "YES\n";
        return 0;
    }
    if (a[r2][c2] == '.' && qq < 2 - int(abs(r1 - r2) + abs(c1 - c2) == 1)) {
        cout << "NO\n";
        return 0;
    }
    if (dfs(r1, c1))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}