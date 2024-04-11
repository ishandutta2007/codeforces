#include <bits/stdc++.h>
using namespace std;
const int N = 500005;

typedef long long LL;
LL Q;

LL power(LL A , LL B) {
    LL res = 1 % Q;
    while (B) {
        if (B & 1)
            (res *= A) %= Q;
        (A *= A) %= Q , B >>= 1;
    }
    return res;
}

struct Matrix {
    int n , m;
    LL a[2][2];
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


void work() {
    LL n , k , l , m;
    cin >> n >> k >> l >> Q;
    LL res = 1 % Q;

    Matrix I(1 , 2) , P(2 , 2);
    I[0][1] = 1 % Q;
    P[0][1] = P[1][0] = P[1][1] = 1 % Q;
    m = n + 2;
    while (m) {
        if (m & 1)
            I = I * P;
        P = P * P , m >>= 1;
    }
    LL p = power(2 , n) , f = I[0][0];
    p = (p - f + Q) % Q;
    for (int i = 0 ; i < l ; ++ i) {
        if (~k & 1)
            res *= f;
        else
            res *= p;
        res %= Q;
        k >>= 1;
    }
    if (k) res = 0;
    cout << res << endl;
}

int main() {
    work();
    return 0;
}