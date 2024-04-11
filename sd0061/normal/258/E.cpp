#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;

int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
int L[N] , R[N] , ncnt;
int a[N] , b[N];
vector<int> c[N];
void dfs(int x , int fa) {
    L[x] = ++ ncnt;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dfs(y , x);
        }
    }
    R[x] = ncnt;
}

struct stree {
    int mn , s , f;
}t[N << 1];
inline int id(int l , int r) { return l + r | l != r; }
#define MID int mid = l + r >> 1
#define THIS p , l , mid , r
#define Left l , mid
#define Right mid + 1 , r

void pushdown(int p , int l , int mid , int r) {
    if (t[p].f) {
        int L = id(Left) , R = id(Right);
        t[L].f += t[p].f , t[R].f += t[p].f;
        t[L].mn += t[p].f , t[R].mn += t[p].f;
        t[p].f = 0;
    }
}
void pushup(int p , int l , int mid , int r) {
    int L = id(Left) , R = id(Right);
    t[p].mn = min(t[L].mn , t[R].mn);
    t[p].s = 0;
    if (t[L].mn == t[p].mn) t[p].s += t[L].s;
    if (t[R].mn == t[p].mn) t[p].s += t[R].s;   
}
void add(int l , int r , int top , int bot , int w) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        t[p].mn += w , t[p].f += w;
        return;
    } MID; pushdown(THIS);
    if (top <= mid) add(Left , top , bot , w);
    if (bot > mid) add(Right , top , bot , w);
    pushup(THIS);
}
void build(int l , int r) {
    int p = id(l , r);
    t[p].s = r - l + 1;
    if (l == r) return; MID;
    build(Left) , build(Right);
}

int res[N];
void DFS(int x , int fa) {
    for (auto it : c[x]) {
        add(0 , n , L[a[it]] , R[a[it]] , 1);
        add(0 , n , L[b[it]] , R[b[it]] , 1);        
    }
    res[x] = max(0 , n - t[id(0 , n)].s);
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            DFS(y , x);
        }
    }
    for (auto it : c[x]) {
        add(0 , n , L[a[it]] , R[a[it]] , -1);
        add(0 , n , L[b[it]] , R[b[it]] , -1);        
    }    
}

void work() {
    int i , x , y;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(1 , 0);
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        a[i] = x , b[i] = y;
        c[x].push_back(i);
        c[y].push_back(i);        
    }
    build(0 , n);
    DFS(1 , 0);
    for (i = 1 ; i <= n ; ++ i)
        printf("%d\n" , res[i]);
}

int main() {
    work();
    return 0;
}