#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Q = 1e9 + 7;
struct Matrix {
    int n , m , a[2][2];
    Matrix (int _n = 0, int _m = 0) {
        n = _n , m = _m;
        memset(a , 0 , sizeof(a));
    }
    Matrix operator * (const Matrix &R) const {
        Matrix res(n , R.m);
        for (int i = 0 ; i < n ; ++ i) {
            for (int j = 0 ; j < m ; ++ j) {
                for (int k = 0 ; k < R.m ; ++ k) {
                    res.a[i][k] += (LL)a[i][j] * R.a[j][k] % Q;
                    res.a[i][k] %= Q;
                }
            }
        }
        return res;
    }
};

int main() {
    LL A , B , n , x;
    cin >> A >> B >> n >> x;
    Matrix I(1 , 2);
    I.a[0][0] = x , I.a[0][1] = 1;
    Matrix P(2 , 2);
    P.a[0][0] = A;
    P.a[1][0] = B;
    P.a[1][1] = 1;
    while (n) {
        if (n & 1) {
            I = I * P;
        }
        P = P * P;
        n >>= 1;
    }
    cout << I.a[0][0] << endl;
}