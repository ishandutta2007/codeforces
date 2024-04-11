#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define foreach(it , h) for (typeof((h).begin()) it = (h).begin() ; it != (h).end() ; ++ it)
const int N = 100005;
int n , m  , t , root;
int st[N];
struct SplayTree {
    int nodecnt , type[N] , f[N] , c[N][2] , s[N];
    //addtional data
    int key[N] , sum[N];
    bool rev[N];
    int malloc(int val) {
        int p = nodecnt ++;
        type[p] = -1 , f[p] = c[p][0] = c[p][1] = 0;
        s[p] = 1 , key[p] = sum[p] = val;
        rev[p] = 0; return p;
    }
    void clear() {
        nodecnt = 0;
        malloc(0) , s[0] = 0;
    }
    inline void pushdown(int x) {
        if (rev[x]) {
            swap(c[x][0] , c[x][1]);
            if (c[x][0]) type[c[x][0]] = 0 , rev[c[x][0]] ^= 1;
            if (c[x][1]) type[c[x][1]] = 1 , rev[c[x][1]] ^= 1;
            rev[x] ^= 1;
        }
    }
    void pushup(int x) {
        s[x] = s[c[x][0]] + 1 + s[c[x][1]];
        sum[x] = sum[c[x][0]] + key[x] + sum[c[x][1]];
    }
    void rotate(int x) {
        int t = type[x] , y = f[x] , z = c[x][!t] ;
        type[x] = type[y] , f[x] = f[y];
        if (~type[x]) c[f[x]][type[x]] = x;
        type[y] = !t , f[y] = x , c[x][!t] = y;
        if (z) type[z] = t , f[z] = y;
        c[y][t] = z , pushup(y);
    }
    void splay(int x) {
        int scnt = 0;
        st[scnt ++] = x;
        for (int i = x ; ~type[i] ; i = f[i])
            st[scnt ++] = f[i];
        for (int i = scnt - 1 ; i >= 0 ; -- i)
            pushdown(st[i]);
        while (~type[x]) {
            int y = f[x];
            (type[y] == type[x]) ?
                rotate(y) : rotate(x);
            if (~type[x])
                rotate(x);
        }
        pushup(x);
    }
    int getKth(int x , int k) {
        while (x) {
            pushdown(x);
            if (s[c[x][0]] + 1 == k)
                return x;
            if (k <= s[c[x][0]])
                x = c[x][0];
            else
                k -= s[c[x][0]] + 1 , x = c[x][1];
        }
        return x;
    }

    void getKth(int x , int k , int w) {
        pushdown(x);
        if (s[c[x][0]] + 1 == k) {
            key[x] += w , sum[x] += w;
        } else if (k <= s[c[x][0]])
            getKth(c[x][0] , k , w);
        else
            getKth(c[x][1] , k - s[c[x][0]] - 1 , w);
        pushup(x);
    }
    void split(int p , int& x , int& y , int S) {
        if (S == s[p]) {x = p , y = 0;return;}
        y = getKth(p , S + 1) , splay(y);
        x = c[y][0] , type[x] = -1;
        c[y][0] = 0 , f[x] = 0 , pushup(y);
    }
    void merge(int& p , int x ,int y) {
        if (!x || !y) {p = x | y ; return;} pushdown(x);
        p = getKth(x , s[x]) , splay(p) , c[p][1] = y;
        type[y] = 1 , f[y] = p , pushup(p);
    }
    int Build(int l , int r) {
        int mid = (l + r) >> 1;
        int x = malloc(1);
        if (l <= mid - 1)
            c[x][0] = Build(l , mid - 1) , f[c[x][0]] = x , type[c[x][0]] = 0;
        if (mid + 1 <= r)
            c[x][1] = Build(mid + 1 , r) , f[c[x][1]] = x , type[c[x][1]] = 1;
        pushup(x); return x;
    }
    void erase(int x , int p) {
        pushdown(x);//TwT
        if (c[x][1]) erase(c[x][1] , p);
        ++ t ; getKth(p , t , key[x]);
        if (c[x][0]) erase(c[x][0] , p);
    }
};
SplayTree T;

void work() {
    int i , j , x , y , l , r , p;
    T.clear();
    scanf("%d%d",&n,&m);
    root = T.Build(1 , n);
    while (m --) {
        scanf("%d" , &i);
        if (i == 2) {
            scanf("%d%d",&l,&r);
            T.split(root , root , x , l);
            T.split(x , x , y , r - l);
            printf("%d\n" , T.sum[x]);
            T.merge(x , x , y);
            T.merge(root , root , x);
        } else {
            scanf("%d",&p);
            if (p + p <= n) {
                T.split(root , x , root , p);
                t = 0;
                T.erase(x , root);
                n -= p;
            } else {
                j = min(p , n - p);
                if (j == 0) {
                    T.rev[root] ^= 1;
                } else {
                    T.split(root , root , x , p - j);
                    T.split(x , x , y , j);
                    T.rev[root] ^= 1;
                    t = 0;
                    T.erase(x , y);
                    T.merge(root , y , root);
                    n -= j;
                }
            }
        }
    }
}

int main() {
    work();
    return 0;
}