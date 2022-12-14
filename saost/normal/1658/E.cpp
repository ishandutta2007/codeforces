#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 2e3 + 5, INF = 0x3c3c3c3c;
int t, n, k, a[N][N], id[N * N], px[N * N], py[N * N];
char kt[N][N];

void Enter() {
    /*n = 2000; k = 198;
    FOR(i, 1, n) FOR(j, 1, n) a[i][j] = i * n + j;*/
    cin >> n >> k;
    FOR(i, 1, n) FOR(j, 1, n) {
        int x;
        cin >> x;
        a[i][j] = x;
        px[x] = i - j;
        py[x] = i + j;
        kt[i][j] = 'G';
    }
}

void Process() {
    int ax = -INF, ay = -INF, bx = INF, by = INF;
    FORD(i, n*n, 1) {
        int idx = px[i];
        int idy = py[i];
        if (idx < ax || idx > bx || idy < ay || idy > by) continue;
        bool ok = true;
        ax = max(ax, idx - k);
        ay = max(ay, idy - k);
        bx = min(bx, idx + k);
        by = min(by, idy + k);
        kt[(idy + idx) / 2][(idy - idx) / 2] = 'M';
    }
    FOR(i, ax, bx) FOR(j, ay, by)
        if ((i+j)%2 == 0 && i+j > 0 && i+j <= n && j-i> 0 && j-i<=n)
            a[(i + j) / 2][(i - j) / 2] = 'M';
    FOR(i, 1, n)
        cout << kt[i] + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // cin >> t;
    t = 1;
    while (t--) {
        Enter();
        Process();
    }
}