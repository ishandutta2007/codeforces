#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
const int M = 500005;
typedef long long LL;

int n , m , pos[N];
string S[N];
char str[N];
int root , last , nodecnt;
int u[N][26] , val[N] , par[N] , bel[N];
inline int newnode(int _val , int _id) {
    ++ nodecnt;
    memset(u[nodecnt] , 0 , sizeof(u[nodecnt]));
    val[nodecnt] = _val , par[nodecnt] = 0 , bel[nodecnt] = _id;
    return nodecnt;
}
void extend(int c , int id = n + 1) {
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
            int nq = newnode(val[p] + 1 , n + 1);
            memcpy(u[nq] , u[q] , sizeof(u[q]));
            par[nq] = par[q];
            par[q] = par[np] = nq;
            while (p && u[p][c] == q)
                u[p][c] = nq , p = par[p];
        }
    }
    last = np;
}
int L[N] , R[N] , ncnt;
vector<int> e[N];
pair<int , int> a[N];
int res[M] , K , W , C[N];
struct Que {
    int x , y , k , id;
    bool operator < (const Que& R) const {
        return k < R.k;
    }
}Q[M << 1];

void dfs(int x) {
    L[x] = ++ ncnt;
    if (bel[x] <= n)
        a[K ++] = make_pair(bel[x] , ncnt);
    for (auto& y : e[x])
        dfs(y);
    R[x] = ncnt;
}

int main() {
    int i , j , l , x , y , k;
    nodecnt = 0;
    scanf("%d%d" , &n , &m);
    root = last = newnode(0 , n + 1);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%s" , str);
        S[i] = str;
        for (j = 0 ; str[j] ; ++ j)
            extend(str[j] - 'a' , i);
        last = root;
    }
    for (i = 1 ; i <= n ; ++ i) {
        x = 1;
        for (j = 0 ; j < S[i].size() ; ++ j)
            x = u[x][S[i][j] - 'a'];
        pos[i] = x; 
    }
    for (i = 2 ; i <= nodecnt ; ++ i)
        e[par[i]].push_back(i);
    dfs(1);
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d" , &x , &y , &k) ;
        k = pos[k] , -- x;
        Q[W ++] = (Que) {L[k] - 1 , R[k] , y , i};
        Q[W ++] = (Que) {L[k] - 1 , R[k] , x ,-i};
    }
    sort(a , a + K);
    sort(Q , Q + W);
    for (i = 0 , j = 0 ; i < W ; ++ i) {
        while (j < K && a[j].first <= Q[i].k) {
            for (k = a[j].second ; k <= nodecnt ; k += k & -k)
                ++ C[k];
            ++ j;
        }
        if (Q[i].id > 0) {
            int &ret = res[Q[i].id];
            for (k = Q[i].y ; k > 0 ; k -= k & -k)
                ret += C[k];
            for (k = Q[i].x ; k > 0 ; k -= k & -k)
                ret -= C[k];
        } else {
            int &ret = res[-Q[i].id];
            for (k = Q[i].y ; k > 0 ; k -= k & -k)
                ret -= C[k];
            for (k = Q[i].x ; k > 0 ; k -= k & -k)
                ret += C[k];
        }
    }
    for (i = 1 ; i <= m ; ++ i)
        printf("%d\n" , res[i]);
    return 0;
}