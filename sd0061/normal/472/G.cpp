#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;
const int N = 200005;
const int M = 1 << 18;
const int S = 205;

struct Complex
{
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
void FFT(Complex P[], int n, int oper)
{
    for (int i = 1, j = 0; i < n - 1; i++) {
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

int n , m , q;
char s[N] , t[N];
int D , L;
int C[S][N];

void work() {
    int i , j , x;
    scanf("%s%s" , s , t);
    n = strlen(s) , m = strlen(t);
    L = sqrt(n * 16) , D = (n + L - 1) / L;
    int len = 1;
    while (len < L + m - 1)
        len <<= 1;
    for (j = 0 ; j < m ; ++ j)
        if (t[m - j - 1] == '0')
            B[j] = Complex(0 , -1);
        else
            B[j] = Complex(1 , 0);
    for ( ; j < len ; ++ j)
        B[j] = 0;
    FFT(B , len , 1);
    for (i = 0 , x = 0 ; i < D ; ++ i , x += L) {
        int size = min(L , n - x);
        for (j = 0 ; j < size ; ++ j)
            if (s[x + j] == '0')
                A[j] = Complex(1 , 0);
            else
                A[j] = Complex(0 , 1);
        for ( ; j < len ; ++ j)
            A[j] = 0;
        FFT(A , len , 1);
        for (j = 0 ; j < len ; ++ j)
            A[j] = A[j] * B[j];
        FFT(A , len , -1);
        for (j = 0 ; j + size <= m ; ++ j)
            C[i][j] += int(A[m - j - 1].x / len + 0.5);
    }
    scanf("%d",&q);
    int pl , ql , pr;
    while (q --) {
        scanf("%d%d%d",&pl,&ql,&len);
        pr = pl + len;
        int l = pl / L , r = pr / L , res = 0;
        if (l == r) {
            for (i = 0 ; i < len ; ++ i)
                res += (s[pl + i] != t[ql + i]);
        } else {
            x = 0;
            for (i = pl ; i < L * (l + 1) ; ++ i)
                res += (s[i] != t[ql + x]) , ++ x;
            for (i = l + 1 ; i < r ; ++ i) {
                res += C[i][ql + x];
                x += L;
            }
            for (i = r * L ; i < pr ; ++ i)
                res += (s[i] != t[ql + x]) , ++ x;
        }
        printf("%d\n" , res);
    }
}

int main() {
    work();
    return 0;
}