#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100005;
const LL Q = 1e9 + 7;
int n , pre[N] , mcnt;
struct edge {
    int x , w , next;
}e[N << 1];
struct stree {
    LL s , l , f;
}t[N << 1];
int q;
vector< pair<int , int> > V[N];
int res[N];

inline int id(int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r

void pushup(int p , int l , int mid , int r) {
    int L = id(Left) , R = id(Right);
    t[p].l = (t[L].l + t[R].l) % Q;
    t[p].s = (t[L].s + t[R].s) % Q;
}
void pushdown(int p , int l , int mid , int r) {
    if (t[p].f) {
        int L = id(Left) , R = id(Right);
        t[L].f += t[p].f , t[L].f %= Q;
        t[R].f += t[p].f , t[R].f %= Q;
        t[L].s += (mid - l + 1) * t[p].f % Q * t[p].f % Q , t[L].s %= Q;
        t[L].s += t[p].f * t[L].l * 2 % Q , t[L].s %= Q;
        t[R].s += (r - mid) * t[p].f % Q * t[p].f % Q , t[R].s %= Q;
        t[R].s += t[p].f * t[R].l * 2 % Q , t[R].s %= Q;
        t[L].l += (mid - l + 1) * t[p].f % Q , t[L].l %= Q;
        t[R].l += (r - mid) * t[p].f % Q , t[R].l %= Q;
        t[p].f = 0;
    }
}
void update(int l , int r , int top , int bot , LL w) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        t[p].f += w , t[p].f %= Q;
        t[p].s += (r - l + 1) * w % Q * w % Q , t[p].s %= Q;
        t[p].s += w * t[p].l * 2 % Q , t[p].s %= Q;
        t[p].l += (r - l + 1) * w % Q , t[p].l %= Q;
        return;
    } MID; pushdown(p , l , mid , r);
    if (top <= mid) update(Left , top , bot , w);
    if (bot > mid) update(Right , top , bot , w);
    pushup(p , l , mid , r);
}
LL query(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p].s;
    MID; pushdown(p , l , mid , r); LL res = 0;
    if (top <= mid) res += query(Left , top , bot);
    if (bot > mid) res += query(Right , top , bot);
    return res % Q;
}

int L[N] , R[N] , ncnt , a[N];
void dfs(int x , int fa) {
    L[x] = ++ ncnt;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            a[ncnt + 1] = (a[L[x]] + e[i].w) % Q;
            dfs(y , x);
        }
    }
    R[x] = ncnt;
}
void Build(int l , int r) {
    int p = id(l , r);
    if (l == r) {
        t[p].l = a[l];
        t[p].s = (LL) a[l] * a[l] % Q;
    } else {
        MID; Build(Left); Build(Right);
        pushup(p , l , mid , r);
    }
}
void DFS(int x , int fa) {
    for (int i = 0 ; i < V[x].size() ; ++ i) {
        int y = V[x][i].first , j = V[x][i].second;
        res[j] = query(1 , n , L[y] , R[y]) << 1 , res[j] %= Q;
        res[j] += (Q - t[id(1 , n)].s) , res[j] %= Q;
    }
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            update(1 , n , 1 , n , e[i].w);
            update(1 , n , L[y] , R[y] , Q - (e[i].w + e[i].w) % Q);
            DFS(y , x);
            update(1 , n , L[y] , R[y] , (e[i].w + e[i].w) % Q);
            update(1 , n , 1 , n , Q - e[i].w);
        }
    }
}

void work() {
    int i , x , y , z;
    scanf("%d",&n);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
    }
    scanf("%d",&q);
    for (i = 0 ; i < q ; ++ i) {
        scanf("%d%d",&x,&y);
        V[x].push_back(make_pair(y , i));
    }
    dfs(1 , 0);
    Build(1 , n);
    DFS(1 , 0);
    for (i = 0 ; i < q ; ++ i) {
        printf("%d\n" , res[i]);
    }
}

int main() {
    work();
    return 0;
}