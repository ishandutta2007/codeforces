#include<bits/stdc++.h>
using namespace std;

#define N 111111
set<int> v[N];
int pa[N], PA[N], Nxt[N], dp[N];
int a[N], rt, last;

bool chk(int x, int y) {
    if(!y) return 0;
    return (x - 1) / rt == (y - 1) / rt;
}

int find(int u) {
    if(pa[u] == u) return u;
    return pa[u] = find(pa[u]);
}

void dfs(int root, int u, int DP) {
    set<int>::iterator it;
    for(it = v[u].begin(); it != v[u].end(); it ++) {
        int ii = *it;
        pa[ii] = root;
        dfs(root, ii, DP + 1);
    }
    dp[u] = DP;
}

int get(int u) {
    if(!u) return 0;
    int fa = find(u);
    if(!Nxt[fa]) last = fa;
    return dp[u] + 1 + get(Nxt[fa]);
}
int main() {
   // freopen("EE.in", "r", stdin);
    //freopen("my.out", "w", stdout);
    int n, m, A, B, x;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    rt = sqrt(n);
    for(int i = 1; i <= n; i ++) {
        int fa = i + a[i];
        if(fa > n) fa = 0;
        if(chk(i, fa)) {
            PA[i] = pa[i] = fa;
            v[fa].insert(i);
        }
        else {
            pa[i] = i, Nxt[i] = fa;
        }
    }
    for(int i = 1; i <= n; i ++) {
        int fa = find(i);
        if(fa == i) dfs(i, i, 0);
    }
    for(int i = 0; i < m; i ++) {
        scanf("%d", &x);
        if(!x) {
            scanf("%d%d", &A, &B);
            if(a[A] == B) continue;
            a[A] = B;
            find(A);
            int fa = A + B;
            if(fa > n) fa = 0;
            int fg = chk(A, fa);
            if(fg) {
                if(pa[A] != A) v[PA[A]].erase(A), v[fa].insert(A);
                else v[fa].insert(A);
                pa[A] = PA[A] = fa;
            }
            else {
                if(pa[A] != A) v[PA[A]].erase(A);
                Nxt[A] = fa;
                pa[A] = A;
            }
            int DDP = 0;
            if(fg) DDP = 1 + dp[fa];
            dfs(find(A), A, DDP);
        }
        else {
            scanf("%d", &A);
            int jump = get(A);
            printf("%d %d\n", last, jump);
        }
    }
    return 0;
}