#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 30005;
const LL inf = -1e18;
struct Matrix {
    LL a[3][3];
    int n , m;
    Matrix (int _n = 0 , int _m = 0) {
        n = _n , m = _m;
        memset(a , 0xC0 , sizeof(a));
    }
    LL* operator [] (const int &x) {
        return a[x];
    }
    const LL* operator [] (const int &x) const {
        return a[x];
    }
};
Matrix operator * (const Matrix &A , const Matrix &B) {
    Matrix C(A.n , B.m);
    for (int i = 0 ; i < A.n ; ++ i)
        for (int j = 0 ; j < A.m ; ++ j)
            for (int k = 0 ; k < B.m ; ++ k)
                C[i][k] = max(C[i][k] , A[i][j] + B[j][k]);
    return C;
}

Matrix t[N << 1];
int n , m , ban[N] , ra[N] , rb[N];
pair<int , int> a[N] , b[N];

LL cost(int x , int y) {
    if (x < 0 || x >= n || y < 0 || y >= n)
        return inf;
    if (ban[x] == y)
        return inf;
    return (LL)a[x].first * b[y].first;
}
Matrix Get(int x) {
    Matrix res(3 , 3);
    res[1][0] = res[2][1] = 0;
    res[2][2] = cost(x , x);
    res[1][2] = cost(x , x - 1) + cost(x - 1 , x);
    res[0][2] = max(res[0][2] , cost(x - 2 , x) + cost(x - 1 , x - 2) + cost(x , x - 1));
    res[0][2] = max(res[0][2] , cost(x , x - 2) + cost(x - 2 , x - 1) + cost(x - 1 , x)); 
    return res;
}
inline int id(int l , int r) {
    return l + r | l != r;                     
}
void rebuild(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (l == r) {
        t[p] = Get(l);
    } else {
        int mid = (l + r) >> 1;
        if (top <= mid)
            rebuild(l , mid , top , bot);
        if (bot > mid)
            rebuild(mid + 1 , r , top , bot);
        t[p] = t[id(l , mid)] * t[id(mid + 1 , r)];
    }
}
int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i].first);
        a[i].second = i;
    }
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &b[i].first);
        b[i].second = i;
    }
    sort(a , a + n);
    sort(b , b + n);
    for (int i = 0 ; i < n; ++ i) {
        ra[a[i].second] = i;
        rb[b[i].second] = i;
    }
    for (int i = 0 ; i < n ; ++ i)
        ban[ra[i]] = rb[i];
    rebuild(0 , n - 1 , 0 , n - 1);
    while (m --) {
        int x , y;
        scanf("%d%d" , &x , &y);
        -- x , -- y;
        swap(ban[ra[x]] , ban[ra[y]]);
        rebuild(0 , n - 1 , ra[x] , min(ra[x] + 2 , n - 1));
        rebuild(0 , n - 1 , ra[y] , min(ra[y] + 2 , n - 1));
        printf("%lld\n" , t[id(0 , n - 1)][2][2]);
    }
   return 0;
}