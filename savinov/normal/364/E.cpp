#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define REP(i,n) for (int i=1;i<=(n);++i)
#define FOR(i,a,b) for (int i=(a);i<=(b);++i)
#define ROF(i,a,b) for (int i=(a);i>=(b);--i)
#define FEC(p,u) for (edge*p=head[u];p;p=p->nxt)
using namespace std;
typedef long long LL;

const int N = 3005;
const int K = 12;

int n, m, k, bl[N][K], br[N][K], cl[K], cr[K], tl[K], tr[K];
LL ans;


char a[2][N][N];
int s[2][N][N];

inline void work(int u, int d, int l, int r, int id){
    if (s[id][d][r] - s[id][u - 1][r] - s[id][d][l - 1] + s[id][u - 1][l - 1] == 0) {
        ans += (d - u + 2) * (d - u + 1) * 1ll * (r - l + 2) * (r - l + 1) / 4;
        return;
    }
    if (d-u > r-l) {
        swap(u, l);
        swap(d, r);
        id ^= 1;
    }

    int m(l+r>>1);
    FOR(i,u,d){
        int t(0);
        bl[i][0] = m;
        char * T = a[id][i];
        ROF(j,m,l){
            if (T[j] == '1') bl[i][++t] = j;
            if (t == k+1) break;
        }
        while (t < k+1) bl[i][++t] = l-1;
        t = 0;
        br[i][0] = m;

        FOR(j,m+1,r){
            if (T[j] == '1') br[i][++t] = j;
            if (t == k+1) break;
        }
        while (t < k+1) br[i][++t] = r+1;
    }
    FOR(i,u,d){
        cl[0] = cr[0] = m;
        REP(t,k+1) cl[t] = l-1, cr[t] = r+1;
        FOR(j,i,d){
            FOR(t,0,k+1) tl[t] = cl[t], tr[t] = cr[t];
            int p(1), q(1);
            REP(t,k+1)
                if (tl[p] > bl[j][q]) cl[t] = tl[p++]; else cl[t] = bl[j][q++];
            p = 1, q = 1;
            REP(t,k+1)
                if (tr[p] < br[j][q]) cr[t] = tr[p++]; else cr[t] = br[j][q++];
            FOR(t,0,k) ans += (cl[t]-cl[t+1])*(cr[k-t+1]-cr[0]);
        }

    }
    if (l < m) work(u, d, l, m-1, id);
    if (m < r) work(u, d, m+1, r, id);
}


int main(){
    scanf("%d%d%d", &n, &m, &k);
    REP(i,n) scanf("%s", a[0][i]+1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[1][j][i] = a[0][i][j];
        }
    }
    for (int t = 0; t < 2; ++t) {
        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < N; ++j) {
                s[t][i][j] = (a[t][i][j] - '0') + s[t][i - 1][j] + s[t][i][j - 1] - s[t][i - 1][j - 1];
            }
        }
    }
    work(1, n, 1, m, 0);
    long long ans2 = ans;
    ans = 0;
    k -= 1;
    if (k >= 0) work(1, n, 1, m, 0);

    cout << ans2 - ans << "\n";
    return 0;
}