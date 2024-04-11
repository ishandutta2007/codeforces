#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;

typedef pair<int , int> val;

val operator + (const val& A , const val& B) {
    return val((A.first + B.first) % Q , (A.second + B.second) % Q);
}
val operator * (const val& A , const val &B) {
    val res((LL)A.first * B.first % Q , ((LL)A.first * B.second + (LL)A.second * B.first) % Q);
    int x = (LL)A.second * B.second % Q;
    res.first += x , res.first %= Q;
    res.second += x , res.second %= Q;
    return res;
}
val P[30];
val getk(int k) {
    val p(1 , 0);
    for (int i = 0 ; i < 30 ; ++ i) {
        if (k >> i & 1) {
            p = p * P[i];
        }
    }
    return p;
}
struct stree {
    val s , f;
    void multi(val x) {
        s = s * x;
        f = f * x;
    }
} t[N << 1];
inline int id(int l , int r) {
    return l + r | l != r;
}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
#define THIS p , l , mid , r
void pushup(int p , int l , int mid , int r) {
    int L = id(Left) , R = id(Right);
    t[p].s = t[L].s + t[R].s;
}
void pushdown(int p , int l , int mid , int r) {
    if (t[p].f != val(1 , 0)) {
        int L = id(Left) , R = id(Right);
        t[L].multi(t[p].f);
        t[R].multi(t[p].f);
        t[p].f = val(1 , 0);
    }
}
int a[N] , n , m;
void build(int l , int r) {
    int p = id(l , r);
    t[p].f = val(1 , 0);
    if (l == r) {
        t[p].s = getk(a[l]);
    } else {
        MID;
        build(Left);
        build(Right);
        pushup(THIS);
    }
}
void modify(int l , int r , int top , int bot , val w) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        t[p].multi(w);
    } else {
        MID; pushdown(THIS);
        if (top <= mid) modify(Left , top , bot , w);
        if (bot > mid) modify(Right , top , bot , w);
        pushup(THIS);
    }
}
val get(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        return t[p].s;
    } else {
        MID; pushdown(THIS);
        if (bot <= mid)
            return get(Left , top , bot);
        else if (top > mid)
            return get(Right , top , bot);
        return get(Left , top , bot) + get(Right , top , bot);
    }
}


int main() {
    P[0] = val(0 , 1);
    for (int i = 1 ; i < 30 ; ++ i) {
        P[i] = P[i - 1] * P[i - 1];
    }
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    build(1 , n);
    for (int i = 0 ; i < m ; ++ i) {
        int o , l , r , x;
        scanf("%d%d%d" , &o , &l , &r);
        if (o == 1) {
            scanf("%d" , &x);
            modify(1 , n , l , r , getk(x));
        } else {
            val v = get(1 , n , l , r);
            printf("%d\n" , v.second);
        }
    }
}