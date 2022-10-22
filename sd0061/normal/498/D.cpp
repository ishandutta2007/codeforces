#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m , a[N];
struct stree {
    pair<int , int> f[60];
}t[N << 1];

stree operator + (stree A , stree B) {
    stree res;
    for (int i = 0 ; i < 60 ; ++ i) {
        res.f[i].first = B.f[A.f[i].first].first;
        res.f[i].second = A.f[i].second + B.f[A.f[i].first].second;
    }
    return res;
}

inline int id (int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r

void Build(int l , int r) {
    int p = id(l , r);
    if (l == r) {
        int x = a[l];
        for (int i = 0 ; i < 60 ; ++ i) {
            if (i % x == 0) {
                t[p].f[i] = make_pair(i + 2 , 0);
            } else {
                t[p].f[i] = make_pair(i + 1 , 0);
            }
            if (t[p].f[i].first >= 60) {
                t[p].f[i].first -= 60;
                t[p].f[i].second += 1;
            }
        }
    } else {
        MID;
        Build(Left);
        Build(Right);
        t[p] = t[id(Left)] + t[id(Right)];
    }
}

void update(int l , int r , int x , int w) {
    int p = id(l , r);
    if (l == r) {
        for (int i = 0 ; i < 60 ; ++ i) {
            if (i % w == 0) {
                t[p].f[i] = make_pair(i + 2 , 0);
            } else {
                t[p].f[i] = make_pair(i + 1 , 0);
            }
            if (t[p].f[i].first >= 60) {
                t[p].f[i].first -= 60;
                t[p].f[i].second += 1;
            }
        }
    } else {
        MID;
        if (x <= mid)
            update(Left , x , w);
        else
            update(Right , x , w);
        t[p] = t[id(Left)] + t[id(Right)];
    }
}

stree query(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p];
    MID;
    if (bot <= mid)
        return query(Left , top , bot);
    if (top > mid)
        return query(Right , top , bot);
    return query(Left , top , bot) + query(Right , top , bot);
}

int main() {
    int i , x , y; char s[10];
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    Build(1 , n);
    scanf("%d",&m);
    while (m --) {
        scanf("%s%d%d", s , &x , &y);
        if (*s == 'C')
            update(1 , n , x , y);
        else {
            -- y;
            stree res = query(1 , n , x , y);
            printf("%d\n" , res.f[0].first + res.f[0].second * 60);
        }
    }
    return 0;
}