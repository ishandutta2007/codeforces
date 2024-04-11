#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
const int M = 524288;

int n , m , K;
char s[N] , t[N];
int cnt[N][4] , ans[N];

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
const double pi = acos(-1.0);
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
Complex A[M] , B[M];

inline int id(char c) {
    if (c == 'A') return 0;
    if (c == 'G') return 1;
    if (c == 'C') return 2;
    if (c == 'T') return 3;
    return -1;
}

void work () {
    scanf("%d%d%d",&n,&m,&K);
    scanf("%s%s" , s , t);

    int i , j , k , x;
    for (i = 0 ; i < n ; ++ i) {
        x = id(s[i]);
        ++ cnt[max(0 , i - K)][x];
        -- cnt[min(n , i + K + 1)][x];
    }
    for (i = 1 ; i < n ; ++ i) {
        for (j = 0 ; j < 4 ; ++ j)
            cnt[i][j] += cnt[i - 1][j];
    }
    int len = 1;
    while (len < n + m - 1)
        len <<= 1;
    for (j = 0 ; j < 4 ; ++ j) {
        memset(A , 0 , sizeof(A));
        memset(B , 0 , sizeof(B));        
        for (i = 0 ; i < m ; ++ i)
            if (id(t[i]) == j)
                A[i] = 1;
        for (i = 0 ; i < n ; ++ i)
            if (cnt[n - i - 1][j])
                B[i] = 1;
        FFT(A , len , 1);
        FFT(B , len , 1);
        for (i = 0 ; i < len ; ++ i)
            A[i] = A[i] * B[i];
        FFT(A , len , -1);
        for (i = 0 ; i <= n - m ; ++ i) {
            ans[i] += lround(A[n - i - 1].x / len);
        }
    }
    int res = 0;
    for (i = 0 ; i <= n - m ; ++ i) {
        //   printf("%d\n" , ans[i]);
        res += (ans[i] == m);
    }
    cout << res << endl;
}

int main () {
    work();
    return 0;
}