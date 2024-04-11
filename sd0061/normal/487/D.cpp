#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m , Q;
char a[N][12];

struct stree {
    pair<int , int> g[11];
}t[N << 1];

inline int id(int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r

stree operator + (const stree& A , const stree& B) {
    stree C;
    for (int i = 1 ; i <= m ; ++ i) {
        if (B.g[i].second < 1 || B.g[i].second > m)
            C.g[i] = B.g[i];
        else
            C.g[i] = A.g[B.g[i].second];
    }
    return C;
}

void Build(int l , int r) {
    int p = id(l , r);
    if (l == r) {
        memset(t[p].g  , 0 , sizeof(t[p].g));
        for (int i = 1 ; i <= m ; ++ i) {
            if (a[l][i] == '>' && a[l][i + 1] == '<')
                t[p].g[i] = t[p].g[i + 1] = make_pair(-1 , -1);
            if (a[l][i] == '^')
                t[p].g[i] = make_pair(l - 1 , i);
        }
        if (a[l][1] == '<')
            t[p].g[1] = make_pair(l , 0);
        for (int i = 2 ; i <= m ; ++ i) {
            if (a[l][i] == '<' && ~t[p].g[i].first)
                t[p].g[i] = t[p].g[i - 1];
        }
        if (a[l][m] == '>')
            t[p].g[m] = make_pair(l , m + 1);
        for (int i = m - 1 ; i > 0 ; -- i) {
            if (a[l][i] == '>' && ~t[p].g[i].first)
                t[p].g[i] = t[p].g[i + 1];
        }
    } else {
        MID;
        Build(Left);
        Build(Right);
        t[p] = t[id(Left)] + t[id(Right)];
    }
}

void update(int l , int r , int x) {
    int p = id(l , r);
    if (l == r) {
        memset(t[p].g  , 0 , sizeof(t[p].g));
        for (int i = 1 ; i <= m ; ++ i) {
            if (a[l][i] == '>' && a[l][i + 1] == '<')
                t[p].g[i] = t[p].g[i + 1] = make_pair(-1 , -1);
            if (a[l][i] == '^')
                t[p].g[i] = make_pair(l - 1 , i);
        }
        if (a[l][1] == '<')
            t[p].g[1] = make_pair(l , 0);
        for (int i = 2 ; i <= m ; ++ i) {
            if (a[l][i] == '<' && ~t[p].g[i].first)
                t[p].g[i] = t[p].g[i - 1];
        }
        if (a[l][m] == '>')
            t[p].g[m] = make_pair(l , m + 1);
        for (int i = m - 1 ; i > 0 ; -- i) {
            if (a[l][i] == '>' && ~t[p].g[i].first)
                t[p].g[i] = t[p].g[i + 1];
        }
    } else {
        MID;
        if (x <= mid)
            update(Left , x);
        else
            update(Right , x);
        t[p] = t[id(Left)] + t[id(Right)];
    }
}
stree query(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p];

    MID;
    if (bot <= mid) return query(Left , top , bot);
    if (top > mid) return query(Right , top , bot);
    return query(Left , top , bot) + query(Right , top , bot);
}

void work() {
    int i , x , y;
    char com[10];
    scanf("%d%d%d",&n,&m,&Q);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , a[i] + 1);
    Build(1 , n);
    while (Q --) {
        scanf("%s%d%d", com , &x , &y);
        if (*com == 'A') {
            pair<int , int> res = query(1 , n , 1 , x).g[y];
            printf("%d %d\n" , res.first , res.second);
        } else {
            scanf("%s" , com);
            a[x][y] = *com;
            update(1 , n , x);
        }
    }
}

int main() {
    work();
    return 0;
}