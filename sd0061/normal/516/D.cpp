#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005;
const int M = 2000005;
int n , m , mcnt , pre[N];
struct edge {
    int x , w , next;
}e[N << 1];
LL d[2][N] , val[N] , q[N];
int D , L[N] , R[N] , ncnt;

#define Left l , mid
#define Right mid + 1 , r

int root[N];
int c[M][2] , nodecnt , s[M];
int newnode(int q) {
    int p = ++ nodecnt;
    c[p][0] = c[p][1] = 0 , s[p] = s[q];
    return p;
}
void add(int& p , int q , int l , int r , int x) {
    if (!p) p = newnode(q);
    ++ s[p]; if (l == r) return;
    int mid = l + r >> 1;
    if (x <= mid) add(c[p][0] , c[q][0] , Left , x);
    if (x > mid) add(c[p][1] , c[q][1] , Right , x);
    if (!c[p][0]) c[p][0] = c[q][0]; if (!c[p][1]) c[p][1] = c[q][1];
}
int get(int p , int l , int r , int top , int bot) {
    if (!p) return 0;
    if (top <= l && r <= bot)
        return s[p];
    int mid = l + r >> 1; int res = 0;
    if (top <= mid) res += get(c[p][0] , Left , top , bot);
    if (bot > mid) res += get(c[p][1] , Right , top , bot);
    return res;
}

void dfs(int x , int fa , LL* dis) {
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dis[y] = dis[x] + e[i].w;
            dfs(y , x , dis);            
        }
    }
}
void DFS(int x , int fa) {
    L[x] = ++ ncnt;
    int j = lower_bound(q , q + D , val[x]) - q + 1;
    add(root[ncnt] , root[ncnt - 1] , 1 , D , j);
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            DFS(y , x);
        }
    }
    R[x] = ncnt;
}

void work() {
    int i , j , k , x , y , z;
    scanf("%d",&n);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;        
    }
    dfs(1 , 0 , d[0]);
    x = 1;
    for (i = 2 ; i <= n ;++ i)
        if (d[0][x] < d[0][i])
            x = i;
    dfs(x , 0 , d[1]);
    y = 1;
    for (i = 2 ; i <= n ;++ i)
        if (d[1][y] < d[1][i])
            y = i;
    d[0][y] = 0;
    dfs(y , 0 , d[0]);
    x = 1;
    for (i = 1 ; i <= n ; ++ i) {
        val[i] = max(d[0][i] , d[1][i]);
        q[D ++] = val[i];
        if (val[i] < val[x])
            x = i;
    }
    sort(q , q + D);
    D = unique(q , q + D) - q;
    DFS(x , 0);
    scanf("%d",&m);
    while (m --) {
        LL l;
        scanf("%I64d" , &l);
        int res = 0;
        for (x = 1 ; x <= n ; ++ x) {
            if (R[x] - L[x] + 1 <= res)
                continue;
            j = upper_bound(q , q + D , val[x] + l) - q;
            res = max(res , get(root[R[x]] , 1 , D , 1 , j) - get(root[L[x] - 1] , 1 , D , 1 , j));
            
        }
        printf("%d\n" , res);
    }
    
}

int main() {
    work();
    return 0;
}