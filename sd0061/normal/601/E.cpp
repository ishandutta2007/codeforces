#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;

const int N = 30005;
const int M = 1005;
const int P = 1e7 + 19;
const int Q = 1e9 + 7;
int n , K , q;
int v[N] , w[N] , st[N] , ed[N];
vector<int> t[N << 1];
inline int id(int l , int r) {
    return l + r | l != r;
}
#define Left l , mid
#define Right mid + 1 , r

void insert(int l , int r , int top , int bot , int x) {
    if (top <= l && r <= bot) {
        t[id(l , r)].push_back(x);
    } else {
        int mid = l + r >> 1;
        if (top <= mid) insert(Left , top , bot , x);
        if (bot > mid) insert(Right , top , bot , x);
    }
}

void query(int l , int r , vector<int> f) {
    int p = id(l , r);
    for (auto &x : t[p]) {
        int V = v[x] , W = w[x];
        for (int i = K ; i >= W ; -- i)
            f[i] = max(f[i] , f[i - W] + V);
    }
    if (l == r) {
        int res = 0;
        for (int i = K ; i > 0 ; -- i) {
            res = ((LL)res * P + f[i]) % Q;
        }
        printf("%d\n" , res);
    } else {
        int mid = l + r >> 1;
        query(Left , f);
        query(Right , f);
    }
}

void work() {
    scanf("%d%d" , &n , &K);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d%d" , &v[i] , &w[i]);
        st[i] = 1;
        ed[i] = -1;
    }
    scanf("%d" , &q);
    int T = 0;
    for (int i = 0 ; i < q ; ++ i) {
        int j , x;
        scanf("%d" , &j);
        if (j == 1) {
            ++ n;
            scanf("%d%d" , &v[n] , &w[n]);
            st[n] = T + 1;
            ed[n] = -1;
        } else if (j == 2) {
            scanf("%d" , &x);
            ed[x] = T;
        } else {
            ++ T;
        }        
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if (!~ed[i])
            ed[i] = T;
        if (st[i] <= ed[i])
            insert(1 , T , st[i] , ed[i] , i);
    }
    vector<int> f(K + 1);
    query(1 , T , f);
}

int main() {
    work();
    return 0;
}