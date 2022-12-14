#include <iostream>
#define FOR(i, l, r) for(int i=l; i<=r; i++)
#define FORD(i, r, l) for(int i=r; i>=l; i--)
#define REP(i, l, r) for(int i=l; i<r; i++)
using namespace std;
int t, n, m, f[505][505], res;
char s[505][505];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    scanf("%d", &t);
    while (t--) {
        res = 0;
        scanf("%d%d", &n, &m);
        FOR(i, 1, n) {
            scanf("\n");
            FOR(j, 1, m) scanf("%c", &s[i][j]);
        }
        FOR(i, 1, n + 1) FOR(j, 1, m + 1) f[i][j] = 0;
        FORD(i, n, 1) FOR(j, 1, m) if (s[i][j] != '.')
        {
            f[i][j] = min(min(f[i+1][j-1], f[i+1][j]), f[i+1][j+1]) + 1;
            res += f[i][j];
        }
        cout << res << '\n';
    }
}