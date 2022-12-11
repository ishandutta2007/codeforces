#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 2011;
const ll md = 1e9 + 7;

int n, m, k, sp;
char a[N][N];

int check(int x, int y, char ch) {
    if (x < 0 || y < 0 || x >= m || y >= n) return 0;
    if (a[y][x] != ch) return 0;
    return 1;
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    scanf("%d %d %d ", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%c ", &a[i][j]);

    for (int x = 0; x < m; x++) {
        sp = 0;
        for (int y = 1; y < n; y++) {
            sp += check(x, y + y, 'U');
            sp += check(x - y, y, 'R');
            sp += check(x + y, y, 'L');
        }
        printf("%d ", sp);
    }

    //return 0;
}