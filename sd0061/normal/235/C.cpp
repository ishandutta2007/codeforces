#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000005;

int root , last , nodecnt;
int u[N][26] , val[N] , par[N] , cnt[N];
vector<int> e[N];
inline int newnode(int _val) {
    ++ nodecnt;
    val[nodecnt] = _val , par[nodecnt] = 0;
    return nodecnt;
}
void extend(int c) {
    int p = last , np = newnode(val[p] + 1);
    ++ cnt[np];
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

int Q;
char str[N];
int f[N] , n;

void dfs(int x) {
    for (auto y : e[x]) {
        dfs(y);
        cnt[x] += cnt[y];
    }
}

void work() {
    nodecnt = 0;
    root = last = newnode(0);
    scanf("%s" , str);
    for (int i = 0 ; str[i] ; ++ i)
        extend(str[i] - 'a');
    for (int i = 2 ; i <= nodecnt ; ++ i)
        e[par[i]].push_back(i);
    dfs(1);
    scanf("%d" , &Q);

    while (Q --) {
        scanf("%s" , str);
        n = strlen(str);
        for (int i = 1 ; i < n ; ++ i) {
            int j = f[i];
            while (j && str[i] != str[j])
                j = f[j];
            f[i + 1] = str[i] == str[j] ? j + 1 : 0;
        }
        int p = (n % (n - f[n]) == 0) ? n - f[n] : n;
        int x = 1 , l = 0 , res = 0;
        for (int i = 0 ; i < n + p - 1 ; ++ i) {
            int c = str[i % n] - 'a';
            while (x && !u[x][c])
                x = par[x] , l = val[x];
            u[x][c] ? (x = u[x][c] , ++ l) : (x = 1 , l = 0);
            if (i >= n - 1) {
                if (l >= n) {
                    while (x && val[par[x]] >= n)
                        x = par[x] , l = val[x];
                    //printf("%d " , cnt[x]);
                    res += cnt[x];
                }
            }
        }
        printf("%d\n" , res);
    }
}

int main() {
    work();
    return 0;
}