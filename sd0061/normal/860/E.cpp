#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

typedef long long LL;

const int N = 500005;
const LL INF = 1LL << 60;
int st[N];
struct LinkCutTree {
    int type[N] , f[N] , p[N] , c[N][2];
    //addtional data
    int key[N] ; int size[N];
    int add[N] ; LL sum[N];

    void malloc(int S) {
        for (int x = 1 ; x <= S ; ++ x) {
            type[x] = -1 , f[x] = p[x] = c[x][0] = c[x][1] = 0;
            add[x] = 0 , key[x] = 0 , sum[x] = 0 ,size[x] = 1;
        }
    }
    inline void pushdown(int x) {
        if (add[x]) {
            key[x] += add[x];
            sum[x] += (LL)add[x] * size[x];
            if (c[x][0]) add[c[x][0]] += add[x];
            if (c[x][1]) add[c[x][1]] += add[x];
            add[x] = 0;
        }
    }
    inline void pushup(int x) {
        pushdown(x); pushdown(c[x][0]); pushdown(c[x][1]);
        size[x] = size[c[x][0]] + 1 + size[c[x][1]];
        sum[x] = sum[c[x][0]] + key[x] + sum[c[x][1]];
    }
    void rotate(int x) {
        int t = type[x] , y = f[x] , z = c[x][!t] ;
        type[x] = type[y] , f[x] = f[y] , p[x] = p[y];
        if (~type[x]) c[f[x]][type[x]] = x;
        type[y] = !t , f[y] = x , p[y] = 0 , c[x][!t] = y;
        if (z) type[z] = t , f[z] = y;
        c[y][t] = z ;
        pushup(y);
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
    int access(int x) { // returns the lowest node last exposed
        int y = 0 , z;
        while (x) {
            splay(x);
            z = c[x][1];
            if (z) { // cut right subtree off
                type[z] = -1;
                f[z] = 0 , p[z] = x;
            }
            c[x][1] = y;// connect to new path
            if (y) {
                f[y] = x;
                p[y] = 0;
                type[y] = 1;
            }
            pushup(x);
            y = x ,  x = p[x];
        };
        return y;
    }
};
LinkCutTree T;

int n , par[N] , d[N];
vector<int> e[N] , v[N];
LL res[N];

void dfs(int x , int dep) {
    d[x] = dep;
    v[dep].push_back(x);
    for (auto &y : e[x]) {
        dfs(y , dep + 1);
    }
}

void work() {
    scanf("%d", &n);
    T.malloc(n);
    int root;
    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        scanf("%d" , &x);
        par[i] = x;
        if (x) {
            e[x].push_back(i);
        } else {
            root = i;
        }
    }
    dfs(root , 1);

    for (int i = 1 ; i <= n ; ++ i) {
        for (auto &x : v[i]) {
            if (par[x]) {
                T.p[x] = par[x];
            }
            T.access(x);
            T.splay(x);
            T.add[x] ++;
        }
        for (auto &x : v[i]) {
            T.access(x);
            T.splay(x);
            //cout << T.sum[]
            res[x] = T.sum[x] - d[x];
        }
    }
    for (int i = 1 ; i <= n ; ++ i) {
        printf("%lld%c" , res[i] , " \n"[i == n]);
    }
}

int main() {
    work();
    return 0;
}