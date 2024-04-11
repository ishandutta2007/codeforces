#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 101;
const int Q = 1e9 + 7;
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
int n , m;

void work() {
    scanf("%d%d",&n,&m);
    Matrix I(1 , 101) , P(101 , 101);
    I[0][0] = 1 , I[0][100] = 1;
    P[100][0] = 1 , P[100][100] = 1;
    for (int i = 0 ; i + 1 < 100 ; ++ i)
        P[i][i + 1] = 1;
    while (n --) {
        int x;
        scanf("%d" , &x);
        ++ P[x - 1][0];
    }
    while (m) {
        if (m & 1)
            I = I * P;
        P = P * P , m >>= 1;
    }
    cout << I[0][0] << endl;
}

int main() {
//    freopen("1" , "r" , stdin);

    work();
    return 0;
}