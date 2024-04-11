#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int Q = 1e9 + 7;
int n , m , L , cnt[N] , p[N * N * N];

struct Matrix {
    int n , m;
    int a[N][N];
    Matrix(int _n , int _m) {
        n = _n , m = _m;
        memset(a , 0 , sizeof(a));
    }
};
Matrix operator * (Matrix A , Matrix B) {
    Matrix res(A.n , B.m);
    for (int i = 0 ; i < A.n ; ++ i) {
        for (int j = 0 ; j < A.m ; ++ j) {
            for (int k = 0 ; k < B.m ; ++ k) {
                res.a[i][k] += (long long)A.a[i][j] * B.a[j][k] % Q;
                res.a[i][k] %= Q;
            }
        }
    }
    return res;
}

int main() {
    int cur = 0 , nxt = 1;
    scanf("%d%d%d" , &n , &L , &m);
    Matrix I(1 , m);
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d" , &x);
        ++ I.a[0][x % m];
    }
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &p[i]);
        ++ cnt[p[i] %= m];
    }
    Matrix P(m , m);
    for (int i = 0 ; i < m ; ++ i) {
        for (int j = 0 ; j < m ; ++ j) {
            P.a[i][(i + j) % m] = cnt[j];
        }
    }
    L -= 2;
    while (L) {
        if (L & 1) {
            I = I * P;
        }
        P = P * P;
        L >>= 1;
    }

    int res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d" , &x);
        x = (x + p[i]) % m;
        //cout << x << endl;
        res += I.a[0][(m - x % m) % m];
        res %= Q;
    }
    cout << res << endl;
}