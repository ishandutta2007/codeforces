#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int N = 30005;
int Q , B , bel[N];

struct query {
    int l , r , id;
    bool operator < (const query &R) const {
        if (bel[l] != bel[R.l])
            return bel[l] < bel[R.l];
        return r < R.r;
        if (bel[l] & 1)
            return r < R.r;
        else
            return R.r < r;
    }
}q[N];

int n , m , a[N] , d[N] , D;
int cnt[N] , res[N];
int fib[N][2];

struct stree {
    int a0 , a1;
    int s;
}t[N << 1];

inline int id(int l , int r) {
    return l + r | l != r;
}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r

void pushup(int p , int l , int mid , int r) {
    int L = id(Left) , R = id(Right);
    t[p].s = t[L].s + t[R].s;
    t[p].a0 = (t[L].a0 + fib[t[L].s][0] * t[R].a0 + fib[t[L].s][1] * t[R].a1) % Q;
    t[p].a1 = (t[L].a1 + fib[t[L].s + 1][0] * t[R].a0 + fib[t[L].s + 1][1] * t[R].a1) % Q;
}
void modify(int l , int r , int x , int w) {
    int p = id(l , r);
    if (l == r) {
        t[p].s = w;
        t[p].a0 = t[p].a1 = w * d[x] % Q;
        return;
    } MID; 
    if (x <= mid)
        modify(Left , x , w);
    else
        modify(Right , x , w);
    pushup(p , l , mid , r);
}
void add(int i) {
    int x = a[i];
    if (++ cnt[x] == 1) {
        modify(0 , D , x , 1);
    }
}
void del(int i) {
    int x = a[i];
    if (-- cnt[x] == 0) {
        modify(0 , D , x , 0);   
    }
}

int main() {        
    scanf("%d%d" , &n , &Q);
    B = sqrt(n);
    
    fib[0][0] = 1 , fib[1][1] = 1;
    for (int i = 2 ; i <= n ; ++ i) {
        fib[i][0] = (fib[i - 2][0] + fib[i - 1][0]) % Q;
        fib[i][1] = (fib[i - 2][1] + fib[i - 1][1]) % Q;        
    }
    
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        d[D ++] = a[i];
        bel[i] = i / B;
    }
    sort(d , d + D);
    D = unique(d , d + D) - d;
    for (int i = 0 ; i < n ; ++ i) {
        a[i] = lower_bound(d , d + D , a[i]) - d;
    }
    scanf("%d" , &m);
    for (int i = 0 ; i < m ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        q[i] = (query) {-- x , -- y , i};
    }
    sort(q , q + m);
    int l = 0 , r = -1;
    for (int i = 0 ; i < m ; ++ i) {
        while (r < q[i].r) {
            add(++ r);
        }
        while (l > q[i].l) {
            add(-- l);
        }
        while (r > q[i].r) {
            del(r --);
        }       
        while (l < q[i].l) {
            del(l ++);
        }
        res[q[i].id] = t[id(0 , D)].a0 % Q;
    }
    for (int i = 0 ; i < m ; ++ i)
        printf("%d\n" , res[i]);
    return 0;
}