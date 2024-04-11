#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m , pre[N] , mcnt , val[N];
struct edge {
    int x , next;
}e[N << 1];
struct opt {
    int x , y , w , id;
    bool operator < (const opt& R) const {
        return w > R.w;
    }
}E[N] , Q[N];
int res[N];
int size[N] , heavy[N] , Fa[N] , Dep[N] , Top[N] , tid[N] , ncnt;
void FindHE(int x , int fa , int dep) {
    size[x] = 1 , Fa[x] = fa , Dep[x] = dep , heavy[x] = 0;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            FindHE(y , x , dep + 1);
            size[x] += size[y];
            if (!heavy[x] || size[y] > size[heavy[x]])
                heavy[x] = y;
        }
    }
}
void ConnectHE(int x , int anc) {
    tid[x] = ++ ncnt , Top[x] = anc;
    if (heavy[x])
        ConnectHE(heavy[x] , anc);
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != Fa[x] && y != heavy[x]) {
            ConnectHE(y , y);
        }
    }
}

struct Status {
    int v , l , r , s;
    Status () {
        v = l = r = s = 0;
    }
    Status (int _v , int _l , int _r , int _s) {
        v = _v , l = _l , r = _r , s = _s;
    }
    Status rev() {
        return Status(v , r , l , s);
    }
};
Status operator + (const Status& L , const Status& R) {
    Status ret;
    ret.v = L.v + R.v - val[L.r] - val[R.l] + val[L.r + R.l];
    ret.l = L.l + (L.l == L.s) * R.l;
    ret.r = R.r + (R.r == R.s) * L.r;
    ret.s = L.s + R.s;
    return ret;
}


inline int id(int l , int r) {
    return l + r | l != r;
}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
Status t[N << 1];

void build(int l , int r) {
    int p = id(l , r);
    if (l == r)
        t[p] = Status(0 , 0 , 0 , 1);
    else {
        MID;
        build(Left);
        build(Right);
        t[p] = t[id(Left)] + t[id(Right)];
    }
}

void update(int l , int r , int x) {
    int p = id(l , r);
    if (l == r) {
        t[p] = Status(val[1] , 1 , 1 , 1);
    } else {
        MID;
        if (x <= mid)
            update(Left , x);
        else
            update(Right , x);
        t[p] = t[id(Left)] + t[id(Right)];
    }
}
Status get(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p];
    else {
        MID;
        if (bot <= mid)
            return get(Left , top , bot);
        if (top > mid)
            return get(Right , top , bot);
        return get(Left , top , bot) + get(Right , top , bot);
    }
}
int query(int x , int y) {
    Status U , D;
    while (Top[x] != Top[y]) {
        if (Dep[Top[x]] > Dep[Top[y]]) {
            U = U + get(1 , n , tid[Top[x]] , tid[x]).rev();
            x = Fa[Top[x]];
        } else {
            D = get(1 , n , tid[Top[y]] , tid[y]) + D;
            y = Fa[Top[y]];
        }
    }
    if (x != y) {
        if (Dep[x] > Dep[y])
            U = U + get(1 , n , tid[y] + 1 , tid[x]).rev() + D;
        else
            U = U + get(1 , n , tid[x] + 1 , tid[y]) + D;
    } else {
        U = U + D;
    }
    return U.v;
}


void work() {
    int i , j ,  x , y , z;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i < n ; ++ i)
        scanf("%d" ,&val[i]);
    memset(pre , -1 , sizeof(pre));
    for (i = 0 ; i + 1 < n ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        E[i] = (opt) {x , y , z , 0};
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    sort(E , E + n - 1);
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        Q[i] = (opt) {x , y , z , i};
    }
    sort(Q , Q + m);
    FindHE(1 , 0 , 0);
    ConnectHE(1 , 1);
    build(1 , n);
    for (i = 0 ; i + 1 < n ; ++ i) {
        if (Dep[E[i].x] < Dep[E[i].y])
            swap(E[i].x ,  E[i].y);
    }
    for (i = 0 , j = 0 ; i < m ; ++ i) {
        while (j + 1 < n && E[j].w >= Q[i].w) {
            update(1 , n , tid[E[j].x]);
            ++ j;
        }
        res[Q[i].id] = query(Q[i].x , Q[i].y);
    }
    for (i = 0 ; i < m ; ++ i)
        printf("%d\n" , res[i]);
}

int main() {
    work();
    return 0;
}