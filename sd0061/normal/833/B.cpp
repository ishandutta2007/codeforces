#include <bits/stdc++.h>
using namespace std;
const int N = 35005;

int n , K , a[N];
int pre[N] , pos[N];
int f[55][N];

struct stree {
    int mx , f;
    void add(int v) {
        mx += v;
        f += v;
    }
} t[N << 1];
inline int id(int l , int r) {
    return l + r | l != r;
}
#define Left l , mid
#define Right mid + 1 , r

void pushdown(int p , int l , int mid , int r) {
    if (t[p].f) {
        t[id(Left)].add(t[p].f);
        t[id(Right)].add(t[p].f);
        t[p].f = 0;
    }
}
void pushup(int p , int l , int mid , int r) {
    t[p].mx = max(t[id(Left)].mx , t[id(Right)].mx);
}
void build(int k , int l , int r) {
    int p = id(l , r);
    t[p].f = 0;
    if (l == r) {
        t[p].mx = f[k][l];
    } else {
        int mid = l + r >> 1;
        build(k , Left); build(k , Right);
        pushup(p , l , mid , r);
    }
}
void add(int l , int r , int top , int bot , int w) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        t[p].add(w);
    } else {
        int mid = l + r >> 1;
        pushdown(p , l , mid , r);
        if (top <= mid) {
            add(Left , top , bot , w);
        }
        if (bot > mid) {
            add(Right , top , bot , w);
        }
        pushup(p , l , mid , r);
    }
}
int get(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        return t[p].mx;
    } else {
        int mid = l + r >> 1 , res = -1 << 30;
        pushdown(p , l , mid , r);
        if (top <= mid) {
            res = max(res, get(Left , top , bot));
        }
        if (bot > mid) {
            res = max(res, get(Right , top , bot));
        }
        pushup(p , l , mid , r);
        return res;
    }
}

int main() {
    scanf("%d%d" , &n , &K);
    memset(pos , -1 , sizeof(pos));
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        pre[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    memset(f[0] , 0xC0 , sizeof(f[0]));
    f[0][0] = 0;
    for (int k = 1 ; k <= K ; ++ k) {
        build(k - 1 , 0 , n);
        for (int i = 0 ; i < n ; ++ i) {
            add(0 , n , pre[i] + 1 , i , 1);
            f[k][i + 1] = get(0 , n , 0 , i);
        }
    }
    printf("%d\n" , f[K][n]);
}