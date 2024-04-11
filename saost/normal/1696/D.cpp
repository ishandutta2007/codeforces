#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
#define MASK(i) (1LL << (i))
using namespace std;
const int N = 1e6 + 5;
int t, n, m, k, a[N], pos[N], mx[N][20], mn[N][20];

void Enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i], pos[a[i]] = i;
}

void Process() {
    FOR(i, 1, n) mx[i][0] = mn[i][0] = a[i];
    REP(j, 1, 20) FOR(i, 1, n - MASK(j) + 1) {
        mx[i][j] = max(mx[i][j - 1], mx[i + MASK(j - 1)][j - 1]);
        mn[i][j] = min(mn[i][j - 1], mn[i + MASK(j - 1)][j - 1]);
    }
    int res = 0, i = 1;
    while (i < n) {
        int i_mx = i + 1, i_mn = i + 1, v_min = a[i], v_max = a[i];
        REPD(j, 20, 0) if (i_mx + MASK(j) - 1 <= n) {
            if (mx[i_mx][j] <= a[i]) v_min = min(v_min, mn[i_mx][j]), i_mx += MASK(j);
        }
        REPD(j, 20, 0) if (i_mn + MASK(j) - 1 <= n) {
            if (mn[i_mn][j] >= a[i]) v_max = max(v_max, mx[i_mn][j]), i_mn += MASK(j);
        }

        i = max(pos[v_min], pos[v_max]);
        ++res;
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}