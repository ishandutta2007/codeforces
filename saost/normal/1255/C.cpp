#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, x, a[N][3], p[N][3], c[N], ans[N], Q[3];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    FOR(i, 1, n-2)
    REP(j, 0, 3) {
        cin >> x;
        a[i][j] = x;
        p[x][c[x]++] = i;
    }
    FOR(i, 1, n) if (c[i] == 1) {
        int d = 0;
        x = p[i][0];
        REP(j, 0, 3) if (a[x][j] != i)
            Q[d++] = a[x][j];
        if (c[Q[0]] > c[Q[1]]) swap(Q[0], Q[1]);
        ans[1] = i;
        ans[2] = Q[0];
        ans[3] = Q[1];
        break;
    }
    FOR(i, 4, n) {
        REP(j, i-3, i) --c[ans[j]];
        REP(j, 0, 3) {
            x = p[ans[i-2]][j];
            bool ok = false;
            REP(w, 0, 3) {
                if (a[x][w] != ans[i-2] && a[x][w] != ans[i-1]) ans[i] = a[x][w];
                if (a[x][w] == ans[i-1]) ok = true;
            }
            if (!ok || ans[i] == ans[i-3]) ans[i] = 0;
            else break;
        }
    }
    FOR(i, 1, n) cout << ans[i] << ' ';
}