#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;

const int N = 2005;
int n , m , pre[N] , mcnt;
vector< pair<int , int> > E;
struct edge {
    int x , next;
}e[N * N * 2];
bool B[N * N];
int dfn[N] , low[N] , ncnt , bel[N];
int val[N] , ans;
vector<int> V;
void dfs(int x , int fa) {
    dfn[x] = low[x] = ++ ncnt;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!dfn[y]) {
            dfs(y , i ^ 1);
            low[x] = min(low[x] , low[y]);
            if (low[y] > dfn[x])
                B[i >> 1] = 1;
        } else if (i != fa && dfn[y] < dfn[x])
            low[x] = min(low[x] , dfn[y]);
    }
}
void DFS(int x) {
    bel[x] = ncnt , ++ val[ncnt];
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!B[i >> 1] && !bel[y])
            DFS(y);
    }
}
int cnt , sum , s[N] , g[N];
void gfs(int x) {
    ++ cnt , dfn[x] = 1 , V.push_back(x);
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!dfn[y])
            gfs(y);
    }
}
void pfs(int x , int fa) {
    s[x] = val[x] , g[x] = 0;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            pfs(y , x);
            s[x] += s[y];
            g[x] += g[y];
            g[x] += s[y] * val[x];
        }
    }
}

int gao(vector<int>& A) {
    int S = 0 , i , j;
    for (i = 0 ; i < A.size() ; ++ i) {
       // printf("%d%c" , A[i] , " \n"[i + 1 == A.size()]);
        S += A[i];
    }
    vector<bool> F(S + 1);
    F[0] = 1 , S = 0;
    for (i = 0 ; i < A.size() ; ++ i) {
        int x = A[i]; S += A[i];
        for (j = S ; j >= x ; -- j)
            F[j] = F[j] | F[j - x];
    }
    int res = 0;
    for (i = 0 ; i <= S ; ++ i) if (F[i])
        res = max(res , i * (S - i));
    return res;
}

int main() {
    int i , k , x , y;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d",&x,&y);
        E.push_back(make_pair(x , y));
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    for (i = 1 ; i <= n ; ++ i)
        if (!dfn[i])
            dfs(i , -1);
    ncnt = 0;
    for (i = 1 ; i <= n ; ++ i)
        if (!bel[i]) {
            ++ ncnt;
            DFS(i);
        }
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 0 ; i < m ; ++ i) {
        x = E[i].first , y = E[i].second;
        x = bel[x] , y = bel[y];
        if (x != y) {
            e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
            e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
        }
    }
    for (i = 1 ; i <= ncnt ; ++ i) {
        ans += val[i] * val[i];
    }
    //cout << ncnt << endl;
    memset(dfn , 0 , sizeof(dfn));
    for (i = 1 ; i <= ncnt ; ++ i) {
        if (dfn[i]) continue;
        cnt = 0 , V.clear();
        gfs(i); sum = 0;
        for (int j = 0 ; j < V.size() ; ++ j) {
            x = V[j];
            pfs(x , 0);
            vector<int> G; int S = 0;
            for (int k = pre[x] ; ~k ; k = e[k].next)
                G.push_back(s[e[k].x]) , S += s[e[k].x];
            sum = max(gao(G) + g[x] , sum );
        }
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}