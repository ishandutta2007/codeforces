#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

int root , last , nodecnt;
int u[N][26] , val[N] , par[N];
inline int newnode(int _val) {
    ++ nodecnt;
    val[nodecnt] = _val , par[nodecnt] = 0;
    return nodecnt;
}
void extend(int c) {
    int p = last , np = newnode(val[p] + 1);
    while (p && u[p][c] == 0)
        u[p][c] = np , p = par[p];
    if (p == 0)
        par[np] = root;
    else {
        int q = u[p][c];
        if (val[p] + 1 == val[q]) {
            par[np] = q;
        } else {
            int nq = newnode(val[p] + 1);
            memcpy(u[nq] , u[q] , sizeof(u[q]));
            par[nq] = par[q];
            par[q] = par[np] = nq;
            while (p && u[p][c] == q)
                u[p][c] = nq , p = par[p];
        }
    }
    last = np;
}
char str[N];
int cnt[N] , a[N];
LL f[N];
void work() {
    nodecnt = 0;
    root = last = newnode(0);
    scanf("%s" , str);
    for (int i = 0 ; str[i] ; ++ i)
        extend(str[i] - 'a');
    for (int i = 1 ; i <= nodecnt ; ++ i)
        ++ cnt[val[i]];
    for (int i = 1 ; i <= nodecnt ; ++ i)
        cnt[i] += cnt[i - 1];
    for (int i = nodecnt ; i > 0  ; -- i)
        a[cnt[val[i]] --] = i;
    while (last)
        f[last] = 1 , last = par[last];
    LL res = 0;
    for (int i = nodecnt ; i > 0 ; -- i) {
        int x = a[i];
        for (int j = 0 ; j < 26 ; ++ j) {
            int y = u[x][j];
            f[x] += f[y];
        }
        res += f[x] * (f[x] + 1) / 2 * (val[x] - val[par[x]]);     
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}