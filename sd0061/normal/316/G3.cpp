#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1100005;

int root , last , nodecnt;
int u[N][27] , val[N] , par[N] , bel[N];
inline int newnode(int _val , int _id = -1) {
    ++ nodecnt;
    val[nodecnt] = _val , par[nodecnt] = 0 , bel[nodecnt] = _id;
    return nodecnt;
}
void extend(int c , int id = -1) {
    int p = last , np = newnode(val[p] + 1 , id);
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

char str[50005] , t[50005];
int n , L[10] , R[10];
vector<int> e[N];
int cnt[N][10] , vis[N];
bool vaild[N];

void dfs(int x) {
    if (~bel[x]) cnt[x][bel[x]] = 1;
    for (auto y : e[x]) {
        dfs(y);
        for (int i = 0 ; i < n ; ++ i)
            cnt[x][i] += cnt[y][i];
    }
    //printf("%d : " , x);
    //for (int i = 0 ; i < n ; ++ i)
    //    printf("%d%c" , cnt[x][i] , " \n"[i + 1 == n]);
    for (int i = 0 ; i < n ; ++ i)
        if (cnt[x][i] < L[i] || cnt[x][i] > R[i])
            return;
    vaild[x] = 1;
    //printf("%d\n" , x);
}

void work() {
    nodecnt = 0;
    root = last = newnode(0);
    scanf("%s%d" , t , &n);
    for (int i = 0 ; t[i] ; ++ i)
        extend(t[i] - 'a');
    extend(26);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%s%d%d" , str , &L[i] , &R[i]);
        for (int j = 0 ; str[j] ; ++ j)
            extend(str[j] - 'a' , i);
        extend(26);
    }
    for (int i = 2 ; i <= nodecnt ; ++ i)
        e[par[i]].push_back(i);
    dfs(1);
    int x = 1 , l = 0;
    LL res = 0;
    for (int i = 0 ; t[i] ; ++ i) {
        int c = t[i] - 'a';
        while (x && !u[x][c])
            x = par[x] , l = val[x];
        u[x][c] ? (x = u[x][c] , ++ l) : (x = 1 , l = 0);

        int y = x , p = l;
        while (y) {
            if (vis[y]) break;
            vis[y] = 1;
            if (vaild[y]) {
                //printf("%d %d\n" , y , p - val[par[y]]);
                res += p - val[par[y]];
                vis[y] = 1;
            }
            y = par[y] , p = val[y];
        }       
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}