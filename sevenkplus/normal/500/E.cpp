#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 200010
#define Z 20

int n, a[N], b[N], fr[N];
int f[N*4], fw[N]; 
int fa[N][Z], fd[N][Z];

int bet(int x, int y) {
    if (x == -1) return y;
    if (y == -1) return x;
    if (fw[x] > fw[y]) return x;
    return y;
}

void blt(int p, int l, int r) {
    if (l == r-1) {f[p] = l; return;}
    int mid = (l+r)/2;
    blt(p*2+1, l, mid);
    blt(p*2+2, mid, r);
    f[p] = bet(f[p*2+1], f[p*2+2]);
}

int ask(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) return f[p];
    int mid = (l+r)/2, S = -1;
    if (L < mid) S = bet(S, ask(p*2+1, l, mid, L, R));
    if (mid < R) S = bet(S, ask(p*2+2, mid, r, L, R));
    return S;
}

void upd(int p, int l, int r, int x, int y) {
    if (l == r-1) {f[p] = l; return;}
    int mid = (l+r)/2;
    if (x < mid) upd(p*2+1, l, mid, x, y);
    else upd(p*2+2, mid, r, x, y);
    f[p] = bet(f[p*2+1], f[p*2+2]);
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d%d", a+i, b+i);
    for (int i = 0; i < n; i ++) fw[i] = a[i]+b[i];
    blt(0, 0, n);
    for (int i = n-1; i >= 0; i --) {
        int le = i;
        int ri = upper_bound(a, a+n, a[i]+b[i])-a;
        int r = ask(0, 0, n, le, ri);
        fw[i] = fw[r];
        fr[i] = ri;
        fr[i] = fr[r];
        upd(0, 0, n, i, fw[i]);
        int z = fr[i];
        fa[i][0] = z;
        fd[i][0] = a[z]-fw[i];
    }
    fa[n][0] = n;
    for (int i = n; i >= 0; i --) 
        for (int l = 1; l < Z; l ++) {
            fa[i][l] = fa[fa[i][l-1]][l-1];
            fd[i][l] = fd[i][l-1] + fd[fa[i][l-1]][l-1];
        }
    int _; scanf("%d", &_);
    while (_--) {
        int x, y;
        scanf("%d%d", &x, &y);
        -- x; --y;
        int S = 0;
        for (int l = Z-1; l >= 0; l --)
            if (fa[x][l] <= y) {
                S += fd[x][l];
                x = fa[x][l];
            }
        printf ("%d\n", S);
    }
    return 0; 
}