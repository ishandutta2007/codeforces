#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

struct dat{
    int l, r, id;
    dat(int l = 0, int r = 0, int id = 0):l(l), r(r), id(id){}
};

bool operator < (dat a, dat b) {
    if(a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}

#define N 201000
#define M 20
int val[M][N];
dat A[N];

int calc(int x, int y) {
    int ans = x;
    for(int i = 0; i < M; i ++) if((y >> i) & 1){
        int k = val[i][x];
        if(A[k].r - A[k].l > A[ans].r - A[ans].l) ans = k;
        x = x + (1 << i);
    }
    return ans;
}

int le[N], ri[N];
int main() {
    //freopen("1.in", "r", stdin);
    int n, m, L, R, C;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++) scanf("%d%d", &A[i].l, &A[i].r), A[i].id = i;
    sort(A, A + n);
    int cnt = 1;
    for(int i = 1; i < n; i ++) if(A[i].r > A[cnt - 1].r) A[cnt ++] = A[i];
    n = cnt;
    for(int i = 0; i < n; i ++) val[0][i] = i;
    for(int i = 1; i < M; i ++) {
        int k = 1 << (i - 1);
        for(int j = 0; j < n; j ++) if(j + k * 2 <= n) {
            int x = val[i - 1][j];
            int y = val[i - 1][j + k];
            if(A[x].r - A[x].l > A[y].r - A[y].l) val[i][j] = x;
            else val[i][j] = y;
        }
    }
    for(int i = 0; i < n; i ++) le[i] = A[i].l, ri[i] = A[i].r;
    ll Mx = 0;
    int vi = 0;
    int ch = 0;
    for(int i = 0; i < m; i ++) {
        scanf("%d%d%d", &L, &R, &C);
        if(R <= A[0].l || L >= A[n - 1].r) continue;
        int id = lower_bound(le, le + n, L) - le;
        int id1 = lower_bound(ri, ri + n, R) - ri;
        if(id && L <= A[id - 1].r) {
            ll va = 1ll * C * (min(R, A[id - 1].r) - L);
            if(Mx < va) {
                Mx = va;
                vi = A[id - 1].id;
                ch = i;
            }
        }
        if(id1 != n && R >= A[id1].l) {
            ll va = 1ll * C * (R - max(A[id1].l, L));
            if(Mx < va) {
                Mx = va;
                vi = A[id1].id;
                ch = i;
            }
        }
        if(id1 <= id) continue;
        int k = calc(id, id1 - id);
        ll va = 1ll * C * (A[k].r - A[k].l);
        if(Mx < va) {
            Mx = va;
            vi = A[k].id;
            ch = i;
        }
    }
    printf("%I64d\n", Mx);
    if(!Mx) return 0;
    printf("%d %d\n", vi + 1, ch + 1);
    return 0;
}