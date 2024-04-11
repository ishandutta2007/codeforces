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
const int N = 100005;
const int Q = 1e9 + 7;
struct Matrix {
    int n , m , a[100][100];
    Matrix (int _n = 0 , int _m = 0) {
        memset(a , 0 , sizeof(a));
        n = _n , m = _m;
    }
    int* operator [] (const int& x) {
        return a[x];
    }
    const int* operator [] (const int& x) const {
        return a[x];
    }    
};
Matrix operator * (const Matrix &A , const Matrix &B) {
    Matrix res(A.n , B.m);
    for (int i = 0 ; i < A.n ; ++ i)
        for (int j = 0 ; j < A.m ; ++ j)
            for (int k = 0 ; k < B.m ; ++ k) {
                res[i][k] += (LL)A[i][j] * B[j][k] % Q;
                res[i][k] %= Q;
            }
    return res;
}
int n , b , K , X , cnt[10];
int main() {
    scanf("%d%d%d%d" , &n , &b , &K , &X);
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d" , &x);
        ++ cnt[x];
    }
    Matrix P(X , X) , I(1 , X);
    for (int i = 0 ; i < X ; ++ i) {
        for (int j = 0 ; j < 10 ; ++ j) {
            int x = (i * 10 + j) % X;
            P[i][x] += cnt[j];
        }
    }
    I[0][0] = 1;
    while (b) {
        if (b & 1)
            I = I * P;
        P = P * P , b >>= 1;
    }
    printf("%d\n" , I[0][K]);
    return 0;
}