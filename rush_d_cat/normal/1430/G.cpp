# include <cstdio>
# include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
# define FOR(i, a, b) for (int i = a; i <= b; ++ i)
# define REP(i, n) FOR (i, 1, n)
# define REP_0N(i, n) FOR (i, 0, n)
# define NR 1100
typedef double ld;

const ld eps = 1e-8, inf = 1e9;
int n, m, type, id[NR], tp[NR]; ld a[NR][NR];
void pivot (int r, int c) {
    swap (id[r + n], id[c]);
    ld t = -a[r][c]; a[r][c] = -1; REP_0N (i, n) a[r][i] /= t;
    REP_0N (i, m) if (a[i][c] && r != i) { t = a[i][c]; a[i][c] = 0; REP_0N (j, n) a[i][j] += t * a[r][j]; }
}
void solve () {
    ld t; REP (i, n) id[i] = i;
    while (true) {
        int i = 0, j = 0; ld _w = -eps;
        REP (k, m) if (a[k][0] < _w) _w = a[i = k][0]; if (!i) break;
        REP (k, n) if (a[i][k] > eps) { j = k; break; } if (!j) { printf ("Infeasible"); return; }
        pivot (i, j);
    }
    while (true) {
        int i = 0, j = 0; ld _w = eps;
        REP (k, n) if (a[0][k] > _w) _w = a[0][j = k]; if (!j) break; _w = inf;
        REP (k, m) if (a[k][j] < -eps && (t = -a[k][0] / a[k][j]) < _w) _w = t, i = k; if (!i) { printf ("Unbounded"); return; }
        pivot (i, j);
    }
   // printf ("%.9f\n", a[0][0]);
    FOR (i, n + 1, n + m) tp[id[i]] = i - n;
    REP (i, n) printf ("%d ", tp[i] ? (int)(a[tp[i]][0] + 0.2) : 0);
}
/*
int main () {
    scanf ("%d%d%d", &n, &m, &type);
    REP (i, n) scanf ("%lf", &a[0][i]);
    REP (i, m) { REP (j, n) scanf ("%lf", &a[i][j]), a[i][j] *= -1; scanf ("%lf", &a[i][0]); }
     for(int i=1;i<=n;i++)cout<<a[0][i]<<" ";printf("\n");
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++) cout<<a[i][j]<<" ";
        printf("\n");
    }
    solve ();
    return 0;
}

*/

int nn,mm; LL f[1000];
int main() {
    scanf("%d%d",&nn,&mm);
    for(int i=1;i<=mm;i++){
        int u,v,w; 
        scanf("%d%d%d",&u,&v,&w);
        f[u]+=w, f[v]-=w;
        ++m; 
        a[m][u]=1, a[m][v]=-1; a[m][0]=-1;
    }
   // printf("!\n");
   // for(int i=1;i<=nn;i++) printf("%lld ", f[i]); printf("\n");
    for(int i=1;i<=nn;i++) {
        a[0][i]=-f[i]; 
    }
    n = nn; 
    /*
    for(int i=1;i<=n;i++)cout<<a[0][i]<<" ";printf("\n");
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++) cout<<a[i][j]<<" ";
        printf("\n");
    }
    */
    solve();
}