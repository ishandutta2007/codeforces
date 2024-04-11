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
typedef long long LL;
using namespace std;
const int N = 200005;
const int Q = 1e9 + 7;

int inverse(int x) {
    return x == 1 ? 1 : (LL)(Q - Q / x) * inverse(Q % x) % Q;
}

int m , n , v[N] , deg[N] , c[N];
vector<int> e[N];
int type[N] , F[N] , L[N] , R[N];

void dfs(int x , int &&ncnt) {
    L[x] = ++ ncnt;
    for (auto &y : e[x]) {
        dfs(y , move(ncnt));
    }
    R[x] = ncnt;
}

struct stree {
    int s , f;
} t[N << 1];
inline int id(int l , int r) {
    return l + r | l != r;
}
#define MID int mid = l + r >> 1
#define THIS p , l , mid , r
#define Left l , mid
#define Right mid + 1 , r
void pushdown(int p , int l , int mid , int r) {
    if (t[p].f != 1) {
        int L = id(Left) , R = id(Right);
        t[L].f = (LL)t[L].f * t[p].f % Q;
        t[R].f = (LL)t[R].f * t[p].f % Q;
        t[L].s = (LL)t[L].s * t[p].f % Q;
        t[R].s = (LL)t[R].s * t[p].f % Q;
        t[p].f = 1;
    }
}
void pushup(int p , int l , int mid , int r) {
    int L = id(Left) , R = id(Right);
    t[p].s = (t[L].s + t[R].s) % Q;
}
void multi(int l , int r , int top , int bot , int w) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        t[p].f = (LL)t[p].f * w % Q;
        t[p].s = (LL)t[p].s * w % Q;
        return;
    } MID; pushdown(THIS);
    if (top <= mid) multi(Left , top , bot , w);
    if (bot > mid) multi(Right , top , bot , w);
    pushup(THIS);
}
int getsum(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot) {        
        return t[p].s;
    } MID; pushdown(THIS); int res = 0;
    if (top <= mid) res += getsum(Left , top , bot);
    if (bot > mid) res += getsum(Right , top , bot);
    return res % Q;
}
void modify(int l , int r , int x , int w) {
    int p = id(l , r);
    if (l == r) {
        t[p].s = w;
        return;
    } MID; pushdown(THIS);
    if (x <= mid) modify(Left , x , w);
    if (x > mid) modify(Right , x , w);
    pushup(THIS);
}
void build(int l , int r) {
    int p = id(l , r);
    t[p].f = 1;
    if (l == r) return; MID;
    build(Left) , build(Right);
}
int main() {
    n = 1;
    scanf("%d%d" , &v[1] , &m);
    for (int i = 0 ; i < m ; ++ i) {
        int j , x;
        scanf("%d%d" , &j , &x);
        if (j == 1) {
            type[i] = ++ n;
            F[n] = x;
            e[x].push_back(n);
            scanf("%d" , &v[n]);
        } else {
            type[i] = -x;
        }
    }    
    dfs(1 , 0);    
    for (int i = 1 ; i <= n ; ++ i)
        c[i] = 1;
    build(1 , n);
    modify(1 , n , L[1] , v[1]);
    for (int i = 0 ; i < m ; ++ i) {
        if (type[i] > 0) {
            int x = type[i] , y = F[x];
            int weight = 1;
            for (int i = L[y] ; i > 0 ; i -= i & -i)
                weight = (LL)weight * c[i] % Q;
            int w = (LL)(deg[y] + 2) * inverse(deg[y] + 1) % Q;
            for (int i = L[y] ; i <= n ; i += i & -i)
                c[i] = (LL)c[i] * w % Q;            
            modify(1 , n , L[x] , (LL)weight * v[x] % Q);
            multi(1 , n , L[y] , R[y] , w);
            w = inverse(w);
            for (int i = R[y] + 1 ; i <= n ; i += i & -i)
                c[i] = (LL)c[i] * w % Q;
            ++ deg[y];            
        } else {
            int x = -type[i];
            int sum = getsum(1 , n , L[x] , R[x]);            
            int weight = 1;
            for (int i = L[F[x]] ; i > 0 ; i -= i & -i)
                weight = (LL)weight * c[i] % Q;
            sum = (LL)sum * inverse(weight) % Q;
            printf("%d\n" , sum);
        }
    }
    return 0;
}