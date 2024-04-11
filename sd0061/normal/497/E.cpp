#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 31;
const int Q = 1e9 + 7;
struct Matrix {
    int n , m;
    LL a[N][N];
    Matrix () {
        n = m = 0;
        memset(a , 0 , sizeof(a));
    }
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

LL n;
int K;
int dig[60] , len;
Matrix M[60][30] , pre[30] , suf[30];

void work() {
    cin >> n >> K;
    int i , j , k;
    while (n) {
        dig[len ++] = n % K;
        n /= K;
    }
    for (i = 0 ; i < K ; ++ i) {
        M[0][i].n = M[0][i].m = K + 1;
        for (j = 0 ; j <= K ; ++ j) {
            M[0][i][j][j] = 1;
            M[0][i][j][i] = 1;
        }
    }
    for (k = 1 ; k < len ; ++ k) {
        pre[0] = M[k - 1][0];
        for (i = 1 ; i < K ; ++ i)
            pre[i] = pre[i - 1] * M[k - 1][i];
        suf[K - 1] = M[k - 1][K - 1];
        for (i = K - 2 ; i >= 0 ; -- i)
            suf[i] = M[k - 1][i] * suf[i + 1];
        for (i = 0 ; i < K ; ++ i) {
            M[k][i] = suf[i];
            if (i)
                M[k][i] = M[k][i] * pre[i - 1];
        }
    }
    Matrix I(1 , K + 1);
    I[0][K] = 1;
    int x = 0;
    for (k = len - 1 ; k >= 0 ; -- k) {
        for (j = 0 ; j < dig[k] ; ++ j) {
            I = I * M[k][(x + j) % K];
        }
        x += dig[k] , x %= K;
    }
    LL res = 0;
    for (i = 0 ; i <= K ; ++ i)
        res += I[0][i] , res %= Q;
    cout << res << endl;
}

int main() {
    work();
    return 0;
}