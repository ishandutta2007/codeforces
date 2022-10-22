#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 128;
const LL Q = 1e9 + 7;

struct Matrix {
    int n , m;
    LL a[N][N];
    Matrix (int _n , int _m) {
        n = _n , m = _m;
        memset(a , 0 , sizeof(a));
    }
    LL* operator [] (int x) {
        return a[x];
    }
    const LL* operator [] (int x) const {
        return a[x];
    }
};

Matrix operator * (const Matrix& A , const Matrix& B) {
    Matrix res(A.n , B.m);
    for (int i = 0 ; i < A.n ; ++ i)
        for (int j = 0 ; j < A.m ; ++ j)
            for (int k = 0 ; k < B.m ; ++ k) {
                res[i][k] += A[i][j] * B[j][k] % Q;
                res[i][k] %= Q;
            }
    return res;
}

int h[8];

int main() {
    int i , j , k , l;
    for (i = 1 ; i <= 7 ; ++ i)
        scanf("%d" , &h[i]);
    Matrix I(1 , 1);
    I[0][0] = 1;
    for (l = 1 ; l <= 7 ; ++ l) {
        for (i = 0 ; i < 1 << l - 1 ; ++ i) {
            I[0][i | (1 << (l - 1))] = I[0][i];
            I[0][i] = 0;
        }
        I.m <<= 1;
        Matrix P(1 << l , 1 << l);
        for (i = 0 ; i < 1 << l ; ++ i)
            for (j = 0 ; j < 1 << l ; ++ j)
                for (k = 0 ; k < 1 << l - 1 ; ++ k) {
                    int x = i & j , y = (k << 1) + 1 + (1 << l);
                    if (x & (y & (y >> 1)))
                        continue;
                    ++ P[i][j];
                }
        int x = h[l];
        while (x) {
            if (x & 1)
                I = I * P;
            P = P * P , x >>= 1;
        }
    }
    printf("%d\n" , (int)I[0][127]);
    return 0;
}