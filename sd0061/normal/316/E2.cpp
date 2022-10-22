#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
const int Q = 1e9;

int n , m , a[N];
LL f[N];

struct stree {
    LL a , b , f;
    int len;
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
        t[L].f %= Q , t[R].f %= Q;
        t[L].a += t[p].f * (f[t[L].len + 1] - 1) % Q , t[L].a %= Q;
        t[L].b += t[p].f * (f[t[L].len] - 1) % Q , t[L].b %= Q;
        t[R].a += t[p].f * (f[t[R].len + 1] - 1) % Q , t[R].a %= Q;
        t[R].b += t[p].f * (f[t[R].len] - 1) % Q , t[R].b %= Q;
        t[p].f = 0;
    }
}
void pushup(int p , int l , int mid , int r) {
    int L = id(Left) , R = id(Right);
    t[p].a = t[L].a + t[R].a * f[t[L].len] % Q + t[R].b * f[t[L].len - 1] % Q;
    t[p].b = t[L].b + t[R].a * f[t[L].len - 1] % Q;
    if (t[L].len > 1)
         t[p].b += t[R].b * f[t[L].len - 2] % Q;
    t[p].a %= Q , t[p].b %= Q;
}
void add(int l , int r , int top , int bot , int w) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        t[p].f += w , t[p].f %= Q;
        t[p].a += w * (f[t[p].len + 1] - 1) % Q , t[p].a %= Q;
        t[p].b += w * (f[t[p].len] - 1) % Q , t[p].b %= Q;       
        return;
    } MID; pushdown(THIS);
    if (top <= mid) add(Left , top , bot , w);
    if (bot > mid) add(Right , top , bot , w);
    pushup(THIS);
}
void update(int l , int r , int x , int w) {
    int p = id(l , r);
    if (l == r) {
        t[p].a = w;
        return;
    } MID; pushdown(THIS);
    if (x <= mid) update(Left , x , w);
    if (x > mid) update(Right , x , w);
    pushup(THIS);
}
void build(int l , int r) {
    int p = id(l , r);
    t[p].len = r - l + 1;
    if (l == r) {
        t[p].a = a[l];
    } else {
        MID;
        build(Left) , build(Right);
        pushup(THIS);
    }
}
LL res;
int len;
void query(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        res += t[p].a * f[len] % Q;
        if (len)
            res += t[p].b * f[len - 1] % Q;
        len += t[p].len , res %= Q;
        return;
    } MID; pushdown(THIS);
    if (top <= mid) query(Left , top , bot);
    if (bot > mid) query(Right , top , bot);
    pushup(THIS);
}
void work() {
    int i , x , y , w;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    f[0] = f[1] = 1;
    for (i = 2 ; i <= n + 2 ; ++ i)
        f[i] = (f[i - 1] + f[i - 2]) % Q;
    build(1 , n);

    while (m --) {
        scanf("%d%d%d",&i,&x,&y);
        if (i == 1)
            update(1 , n , x , y);
        if (i == 2) {
            res = len = 0;
            query(1 , n , x , y);
            printf("%lld\n" , res);
        }
        if (i == 3) {
            scanf("%d",&w);
            add(1 , n , x , y , w);
        }                     
    }
        

    
}

int main() {
    work();
    return 0;
}