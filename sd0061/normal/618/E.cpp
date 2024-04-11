#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 300005;

int n , m;
long double SIN[360] , COS[360];

struct Matrix {
    int n , m;
    long double a[2][2];
    Matrix (int _n = 0, int _m = 0) {
        n = _n , m = _m;
        memset(a , 0 , sizeof(a));
    }
    void toI() {
        for (int i = 0 ; i < n ; ++ i)
            for (int j = 0 ; j < m ; ++ j)
                a[i][j] = (i == j);
    }
    long double* operator [] (const int &x) {
        return a[x];
    }
    const long double* operator [] (const int &x) const { 
        return a[x];
    }
    Matrix operator * (const Matrix &R) const {
        Matrix res(n , R.m);
        for (int i = 0 ; i < n ; ++ i)
            for (int j = 0 ; j < m ; ++ j)
                for (int k = 0 ; k < R.m ; ++ k)
                    res[i][k] += a[i][j] * R[j][k];
        return res;
    }
    Matrix operator + (const Matrix &R) const {
        Matrix res(n , m);
        for (int i = 0 ; i < n ; ++ i)
            for (int j = 0 ; j < m ; ++ j)
                res[i][j] = a[i][j] + R[i][j];
        return res;
    }
    Matrix operator - (const Matrix &R) const {
        Matrix res(n , m);
        for (int i = 0 ; i < n ; ++ i)
            for (int j = 0 ; j < m ; ++ j)
                res[i][j] = a[i][j] - R[i][j];
        return res;
    }
};


struct stree {
    Matrix s = Matrix(1 , 2);
    Matrix f = Matrix(2 , 2);  
}t[N << 1];
inline int id(int l , int r) {
    return l + r | l != r;
}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
Matrix a[N];
void build(int l , int r) {
    int p = id(l , r);
    t[p].f.toI();
    if (l == r) {
        t[p].s = a[r + 1] - a[l];
    } else {
        MID;
        build(Left);
        build(Right);
        t[p].s = t[id(Left)].s + t[id(Right)].s;
    }
}
void multi(int l , int r , int top , int bot , Matrix &w) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        t[p].s = t[p].s * w;
        t[p].f = t[p].f * w;
    } else {
        MID;
        int L = id(Left) , R = id(Right);
        t[L].s = t[L].s * t[p].f , t[L].f = t[L].f * t[p].f;
        t[R].s = t[R].s * t[p].f , t[R].f = t[R].f * t[p].f;
        t[p].f.toI();
        if (top <= mid) multi(Left , top , bot , w);
        if (bot > mid) multi(Right , top , bot , w);
        t[p].s = t[L].s + t[R].s;
    }
}
void trans(int l , int r , int x , int e) {
    int p = id(l , r);
    if (x <= l && r <= x) {
        Matrix &w = t[p].s;
        // printf("%f\n" , (double)w[0][0]);
        double len = sqrt(w[0][0] * w[0][0] + w[0][1] * w[0][1]);
        // printf("%.10f\n" , len);
        w[0][0] /= len , w[0][1] /= len;
        len += e;
        // printf("%.10f\n" , len);
        w[0][0] *= len , w[0][1] *= len;                
    } else {
        MID;
        int L = id(Left) , R = id(Right);
        t[L].s = t[L].s * t[p].f , t[L].f = t[L].f * t[p].f;
        t[R].s = t[R].s * t[p].f , t[R].f = t[R].f * t[p].f;
        t[p].f.toI();
        if (x <= mid) trans(Left , x , e);
        if (x > mid) trans(Right , x , e);
        t[p].s = t[L].s + t[R].s;
    }
}

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < 360 ; ++ i) {
        double x = i * acos(-1) / 180;
        SIN[i] = sin(x);
        COS[i] = cos(x);
    }
    ++ n;
    for (int i = 1 ; i <= n ; ++ i) {
        a[i].n = 1 , a[i].m = 2;
        int x = i - 1 , y = 0;
        a[i][0][0] = x;
        a[i][0][1] = y;
    }
    build(1 , n - 1);
    while (m --) {
        int i , x , y;
        scanf("%d%d%d" , &i , &x , &y);
        if (i == 1) {
            trans(1 , n - 1 , x , y);
        } else {
            Matrix w(2 , 2);
            y = (360 - y) % 360;
            w[0][0] = COS[y] , w[0][1] = SIN[y];
            w[1][0] = -SIN[y] , w[1][1] = COS[y];
            multi(1 , n - 1 , x , n - 1 , w);
        }
        Matrix &res = t[id(1 , n - 1)].s;
        printf("%.15f %.15f\n" , (double)res[0][0] , (double)res[0][1]);
    }
    return 0;
}