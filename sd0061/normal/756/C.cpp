#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

inline int id(int l , int r) {
    return l + r | l != r;
}
#define Left l , mid
#define Right mid + 1 , r

struct stree {
    int mx , f;
    void update(int d) {
        f += d;
        mx += d;
    }
} t[N << 1];
void pushdown(int p , int l , int mid , int r) {
    if (t[p].f) {
        t[id(Left)].update(t[p].f);
        t[id(Right)].update(t[p].f);
        t[p].f = 0;
    }
}
void pushup(int p , int l , int mid , int r) {
    t[p].mx = max(t[id(Left)].mx , t[id(Right)].mx);
}
void update(int l , int r , int top , int bot , int w) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        t[p].update(w);
    } else {
        int mid = l + r >> 1;
        pushdown(p , l , mid , r);
        if (top <= mid) update(Left , top , bot , w);
        if (bot > mid) update(Right , top , bot , w);
        pushup(p , l , mid , r);
    }
}
int find(int l , int r) {
    if (l == r) {
        return l;
    } else {
        int mid = l + r >> 1;
        pushdown(id(l , r) , l , mid , r);
        if (t[id(Right)].mx > 0) {
            return find(Right);
        } else {
            return find(Left);
        }
    }
}

int pos[N] , n;

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        int p , o , x;
        scanf("%d%d" , &p , &o);
        if (o == 1) {
            scanf("%d" , &x);
            pos[p] = x;
            update(1 , n , 1 , p , 1);
        } else {
            update(1 , n , 1 , p , -1);
        }

        if (t[id(1 , n)].mx <= 0) {
            puts("-1");
        } else {
            printf("%d\n" , pos[find(1 , n)]);
        }
    }
}