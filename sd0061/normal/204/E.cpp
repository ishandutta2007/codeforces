#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400005;

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
vector<string> S;
int n , K;
char str[N];
vector<int> e[N];
int cnt[N];
set<int> h[N];

void dfs(int x) {
    if (~bel[x])
        h[x].insert(bel[x]);
    for (auto y : e[x]) {
        dfs(y);
        if (h[x].size() < h[y].size())
            swap(h[x] , h[y]);
        h[x].insert(h[y].begin() , h[y].end());
    }
    cnt[x] = h[x].size();
}

void work() {
    nodecnt = 0;
    root = last = newnode(0);
    scanf("%d%d",&n,&K);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        for (int j = 0 ; str[j] ; ++ j)
            extend(str[j] - 'a' , i);
        extend(26);
        S.push_back(str);
    }
    for (int i = 2 ; i <= nodecnt ; ++ i)
        e[par[i]].push_back(i);
    dfs(1);
    for (int i = 0 ; i < n ; ++ i) {
        int x = 1 , l = 0;
        LL res = 0;
        for (int j = 0 ; j < S[i].size() ; ++ j) {
            int c = S[i][j] - 'a';
            while (x && !u[x][c])
                x = par[x];
            if (u[x][c])
                x = u[x][c] , ++ l;
            else
                x = 1 , l = 0;
            while (x && cnt[x] < K)
                x = par[x] , l = val[x];
            res += l;
        }
        printf("%lld\n" , res);
    }
}

int main() {
    work();
    return 0;
}