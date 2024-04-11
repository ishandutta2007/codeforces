#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1205;
const int M = (1 << 21) + 233;
const double pi = acos(-1);
int n , m , r , c , W , S , len;
char T[N][N] , P[N][N];
int res[M] , id[N][N];

struct Complex {
    double x , y;
    Complex () {x = y = 0;}
    Complex (double _x , double _y) {x = _x , y = _y;}
    Complex operator + (const Complex& r) const {
        return Complex(x + r.x , y + r.y);
    }
    Complex operator - (const Complex& r) const {
        return Complex(x - r.x , y - r.y);
    }
    Complex operator * (const Complex& r) const {
        return Complex(x * r.x - y * r.y , x * r.y + y * r.x);
    }
    int operator = (const int a) {
        *this = Complex(a , 0);
        return a;
    }
};
Complex A[M] , B[M];

void FFT(Complex P[], int n, int oper) {
    for (int i = 1, j = 0; i < n - 1; i ++) {
        for (int s = n; j ^= s >>= 1, ~j & s;);
        if (i < j) {
            swap(P[i], P[j]);
        }
    }
    for (int d = 0; (1 << d) < n; d++) {
        int m = 1 << d, m2 = m * 2;
        double p0 = pi / m * oper;
        Complex unit_p0(cos(p0) , sin(p0));
        for (int i = 0; i < n; i += m2) {
            Complex unit(1 , 0);
            for (int j = 0; j < m; j++) {
                Complex &P1 = P[i + j + m], &P2 = P[i + j];
                Complex t = unit * P1;
                P1 = P2 - t;
                P2 = P2 + t;
                unit = unit * unit_p0;
            }
        }
    }
}

void conv(Complex *a , Complex *b , int *c , int multi) {
    // c[x] = \sum{a[i] * b[x + i]}
    int num = 0;
    reverse(a , a + S);
    FFT(a , len , 1);
    FFT(b , len , 1);
    for (int i = 0 ; i < len ; ++ i) {
        a[i] = a[i] * b[i];
    }
    FFT(a , len , -1);
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < m ; ++ j) {
            int v = (a[S - 1 + (id[i][j])].x / len + 0.5);
            c[num ++] += v * multi;
        }
    }
}


int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%s" , T[i]);
    }
    for (int i = 0 ; i < n + n ; ++ i) {
        for (int j = 0 ; j < m + m ; ++ j) {
            T[i][j] = T[i % n][j % m];
        }
    }
    scanf("%d%d" , &r , &c);
    for (int i = 0 ; i < r ; ++ i) {
        scanf("%s" , P[i]);
    }
    W = m + m + c;
    S = r * W;
    len = 1;
    while (len <  (n + n + r) * W) {
        len <<= 1;
    }
    memset(A , 0 , sizeof(A));
    memset(B , 0 , sizeof(B));
    for (int i = 0 ; i < n + n ; ++ i) {
        for (int j = 0 ; j < m + m ; ++ j) {
            id[i][j] = i * W + j;
            B[id[i][j]] = (T[i][j] - 'a') * (T[i][j] - 'a');
        }
    }
    for (int i = 0 ; i < r ; ++ i) {
        for (int j = 0 ; j < c ; ++ j) {
            A[id[i][j]] = (P[i][j] != '?');
        }
    }
    conv(A , B , res , 1);
    memset(A , 0 , sizeof(A));
    memset(B , 0 , sizeof(B));
    for (int i = 0 ; i < n + n ; ++ i) {
        for (int j = 0 ; j < m + m ; ++ j) {
            B[id[i][j]] = (T[i][j] - 'a');
        }
    }
    for (int i = 0 ; i < r ; ++ i) {
        for (int j = 0 ; j < c ; ++ j) {
            A[id[i][j]] = (P[i][j] - 'a') * (P[i][j] != '?');
        }
    }
    conv(A , B , res , -2);
    memset(A , 0 , sizeof(A));
    memset(B , 0 , sizeof(B));
    for (int i = 0 ; i < n + n ; ++ i) {
        for (int j = 0 ; j < m + m ; ++ j) {
            B[id[i][j]] = 1;
        }
    }
    for (int i = 0 ; i < r ; ++ i) {
        for (int j = 0 ; j < c ; ++ j) {
            A[id[i][j]] = (P[i][j] - 'a') * (P[i][j] - 'a') * (P[i][j] != '?');
        }
    }
    conv(A , B , res , 1);
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < m ; ++ j) {
            if (res[i * m + j] == 0) {
                putchar('1');
            } else {
                putchar('0');
            }
        }
        puts("");
    }
}