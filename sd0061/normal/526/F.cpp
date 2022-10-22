#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300005;
int n , a[N] , p[N];

struct stree {
    int f , mn , s;
}t[N << 1];
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
inline int id(int l , int r) {
    return l + r | l != r;
}
void pushdown(int l , int mid , int r) {
    int p = id(l , r);
    if (t[p].f) {
        int L = id(Left) , R = id(Right);
        t[L].mn += t[p].f , t[R].mn += t[p].f;
        t[L].f += t[p].f , t[R].f += t[p].f;
        t[p].f = 0;
    }
}
void pushup(int l , int mid , int r) {
    int p = id(l , r) , L = id(Left) , R = id(Right);
    t[p].mn = min(t[L].mn , t[R].mn);
    t[p].s = 0;
    if (t[p].mn == t[L].mn) t[p].s += t[L].s;
    if (t[p].mn == t[R].mn) t[p].s += t[R].s;    
}
void build(int l , int r) {
    if (l == r) {
        int p = id(l , r);
        t[p].s = 1;
        t[p].mn = 1 << 30;
    } else {
        MID; 
        build(Left);
        build(Right);
        pushup(l , mid , r);
    }
}
void add(int l , int r , int top , int bot , int w) {
    if (top <= l && r <= bot) {
        int p = id(l , r);
        t[p].f += w;
        t[p].mn += w;        
    } else {
        MID; pushdown(l , mid ,  r);
        if (top <= mid) add(Left , top , bot , w);
        if (bot > mid) add(Right , top , bot , w);
        pushup(l , mid , r);
    }
}

void work() {
    int i , x , y;
    scanf("%d" , &n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d%d",&x,&y);
        a[x] = y , p[y] = x;
    }
    build(1 , n);
    LL res = 0;
    for (i = 1 ; i <= n ; ++ i) {
        add(1 , n , i , i , -1 << 30);
        add(1 , n , 1 , i , 1);
        if (a[i] > 1 && p[a[i] - 1] < i)
            add(1 , n , 1 , p[a[i] - 1] , -1);
        if (a[i] < n && p[a[i] + 1] < i)
            add(1 , n , 1 , p[a[i] + 1] , -1);        
        res += t[id(1 , n)].s;
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}