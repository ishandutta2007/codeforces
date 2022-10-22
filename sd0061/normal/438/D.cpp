#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 100005
int n , Q , a[N];
struct stree {
    int m;
    LL s;
}t[N << 1];

inline int id (int l , int r) {return l + r | l != r;}
#define MID int mid = (l + r) >> 1
#define Left l , mid
#define Right mid + 1 , r

inline void pushup(int p , int l , int mid , int r) {
    int L = id(Left) , R = id(Right);
    t[p].m = max(t[L].m , t[R].m);
    t[p].s = t[L].s + t[R].s;
}

void Build(int l , int r) {
    int p = id(l , r);
    if (l == r) {
        t[p].s = t[p].m = a[l];
    } else {
        MID; Build(Left); Build(Right);
        pushup(p , l , mid , r);
    }
}

LL Query(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p].s;
    MID; LL res = 0;
    if (top <= mid) res += Query(Left , top , bot);
    if (bot > mid) res += Query(Right , top , bot);
    return res;
}
void modify(int l , int r , int x , int w) {
    int p = id(l , r);
    if (l == r) {
        t[p].m = t[p].s = w;
        return;
    } MID;
    if (x <= mid)
        modify(Left , x , w);
    else
        modify(Right , x , w);
    pushup(p , l , mid , r);
}
void mod(int l , int r , int top , int bot , int x) {
    int p = id(l , r);
    if (t[p].m < x) return;
    if (l == r) {
        t[p].m = t[p].s = t[p].m % x;
        return;
    } MID;
    if (top <= mid) mod(Left , top , bot , x);
    if (bot > mid) mod(Right , top , bot , x);
    pushup(p , l , mid , r);
}

void work() {
    int i , x , l , r;
    scanf("%d%d",&n,&Q);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    Build(1 , n);
    while (Q --) {
        scanf("%d" , &i);
        if (i == 1) {
            scanf("%d%d",&l,&r);
            printf("%I64d\n" , Query(1 , n , l , r));
        }
        if (i == 2) {
            scanf("%d%d%d",&l,&r,&x);
            mod(1 , n , l , r , x);
        }
        if (i == 3) {
            scanf("%d%d",&l,&x);
            modify(1 , n , l , x);
        }
    }
}

int main()
{
    work();
    return 0;
}