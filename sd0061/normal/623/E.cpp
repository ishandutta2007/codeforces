#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 1 << 16;
const int Q = 1e9 + 7;
const int M = 32768;
int K , p[N] , I[N] , ans[N];
int len , t1[N] , t2[N] , t3[N];

struct Complex {
    double x , y;
    Complex (double _x = 0 , double _y = 0) {
        x = _x , y = _y;
    }
    Complex operator + (const Complex &r) const {
        return Complex(x + r.x , y + r.y);
    }
    Complex operator - (const Complex &r) const {
        return Complex(x - r.x , y - r.y);
    }
    Complex operator * (const Complex &r) const {
        return Complex(x * r.x - y * r.y , x * r.y + y * r.x);
    }
    Complex conj () const {
        return Complex(x , -y);
    }
    double operator = (const double a) {
        *this = Complex(a , 0);
        return a;
    }
};
const double pi = acos(-1.0);
Complex w[N]; int rev[N];

void FFTperpare(int n) {
    int LN = __builtin_ctz(n);
    for (int i = 0 ; i < n ; ++ i) {
        double ang = 2 * pi * i / n;
        w[i] = Complex(cos(ang) , sin(ang));
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (LN - 1));
    }
}

void FFT(Complex P[], int n, int oper) {
    for (int i = 0 ; i < n ; i ++) {
        if (i < rev[i]) {
            swap(P[i], P[rev[i]]);
        }
    }
    for (int d = 0; (1 << d) < n; d++) {
        int m = 1 << d, m2 = m * 2 , rm = n / m2;
        for (int i = 0; i < n; i += m2) {
            for (int j = 0; j < m; j++) {
                Complex &P1 = P[i + j + m], &P2 = P[i + j];
                Complex t = w[rm * j] * P1;
                P1 = P2 - t;
                P2 = P2 + t;
            }
        }
    }
}

Complex A[N] , B[N] , C1[N] , C2[N];
void convolution(int *a , int *b , int *res) {
    for (int i = 0 ; i < len ; ++ i) {
        A[i] = Complex(a[i] / M , a[i] % M);
        B[i] = Complex(b[i] / M , b[i] % M);
    }
    FFT(A , len , 1);
    FFT(B , len , 1);
    for (int i = 0 ; i < len ; ++ i) {
        int j = i ? len - i : i;
        Complex a1 = (A[i] + A[j].conj()) * Complex(0.5 , 0);
        Complex a2 = (A[i] - A[j].conj()) * Complex(0 , -0.5);
        Complex b1 = (B[i] + B[j].conj()) * Complex(0.5 , 0);
        Complex b2 = (B[i] - B[j].conj()) * Complex(0 , -0.5);
        Complex c11 = a1 * b1 , c12 = a1 * b2;
        Complex c21 = a2 * b1 , c22 = a2 * b2;
        C1[j] = c11 + c12 * Complex(0 , 1);
        C2[j] = c21 + c22 * Complex(0 , 1);
    }
    FFT(C1 , len , -1);
    FFT(C2 , len , -1);
    for (int i = 0 ; i <= K ; ++ i) {
        int x = (LL)(C1[i].x / len + 0.5) % Q;
        int y1 = (LL)(C1[i].y / len + 0.5) % Q;
        int y2 = (LL)(C2[i].x / len + 0.5) % Q;
        int z = (LL)(C2[i].y / len + 0.5) % Q;
        res[i] = ((LL)x * M * M + (LL)(y1 + y2) * M + z) % Q;
    }
}
void cal(int *res , int *a , int *b , int n , int m) {
    int two = 1;
    for (int i = 0 ; i < m ; ++ i) {
        two <<= 1 , two %= Q;
    }
    int fac = 1;
    for (int i = 0 ; i < len ; ++ i) {
        t3[i] = (LL)a[i] * fac % Q;
        fac = (LL)fac * two % Q;
    }
    convolution(t3 , b , res);
}

void getans(int n , int *res) {
    if (n == 1) {
        memcpy(res , I , sizeof(int) * len);
    } else {
        getans(n >> 1 , t1);
        cal(t2 , t1 , t1 , n >> 1 , n >> 1);
        if (n & 1) {
            cal(res , t2 , I , n - 1 , 1);
        } else {
            memcpy(res , t2 , sizeof(int) * len);
        }
    }
}

int main() {
    LL m;
    int n;
    cin >> m >> K;
    if (m > K) {
        puts("0");
        return 0;
    }
    n = m;
    p[0] = p[1] = I[0] = I[1] = 1;
    for (int i = 2 ; i <= K ; ++ i) {
        I[i] = (LL)(Q - Q / i) * I[Q % i] % Q;
        p[i] = (LL)p[i - 1] * i % Q;
    }
    for (int i = 2 ; i <= K ; ++ i) {
        I[i] = (LL)I[i] * I[i - 1] % Q;
    }
    len = 1;
    while (len < K + K + 5)
        len <<= 1;
    FFTperpare(len);

    I[0] = 0;
    getans(n , ans);
    I[0] = 1;
    int res = 0;
    for (int i = 1 ; i <= K ; ++ i) {
        res += (LL)ans[i] * p[K] % Q * I[K - i] % Q;
        res %= Q;
    }
    printf("%d\n" , res);
    return 0;
}