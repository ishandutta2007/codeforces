#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int N = 100000;

struct Ring{
    ull a[5];
    Ring() {
        memset(a, 0, sizeof a);
    }
    Ring operator + (Ring r) {
        Ring R = r;
        for (int i = 0; i < 5; i ++) R.a[i] += a[i];
        return R;
    }
    void operator += (Ring r) {
        (*this) = (*this) + r;
    }
    Ring operator * (Ring r) {
        Ring R;
        for (int i = 0; i < 5; i ++)
            for (int j = 0; j < 5; j ++)
                i + j < 5 ? R.a[i+j] += a[i] * r.a[j] : R.a[i+j-5] -= a[i] * r.a[j];
        return R;
    }
    void operator *= (Ring r) {
        (*this) = (*this) * r;
    }
    Ring operator << (int k) {
        Ring R;
        for (int i = 0; i < 5; i ++) {
            int j = (i + k) % 10;
            j < 5 ? R.a[j] = a[i] : R.a[j-5] = -a[i];
        }
        return R;
    }
    ull real() {
        return a[0] + a[1];
    }
} x[N], w[10], tmp[10];

ull fpow(ull a, ull n) {
    ull rlt = 1;
    while (n) {
        if (n & 1) rlt *= a;
        a *= a, n >>= 1;
    }
    return rlt;
}

Ring fpow(Ring a, int n) {
    Ring rlt;
    rlt.a[0] = 1;
    while (n) {
        if (n & 1) rlt *= a;
        a *= a, n >>= 1;
    }
    return rlt;
}

void DFT(Ring *P, int op) {
    for (int i = 1; i < N; i *= 10)
        for (int p = i * 10, j = 0; j < N; j += p)
            for (int k = 0; k < i; k ++) {
                for (int x = 0; x < 10; x ++) tmp[x] = P[j+k+x*i];
                for (int x = 0; x < 10; x ++) {
                    Ring &r = P[j+k+x*i];
                    r = Ring();
                    for (int y = 0; y < 10; y ++)
                        r += tmp[y] << x * y * op;
                }
            }
}

int n;

int main() {
    scanf("%d", &n);
    for (int i = 0, k; i < n; i ++) {
        scanf("%d", &k);
        x[k].a[0] ++;
    }
    DFT(x, 1);
    for (int i = 0; i < N; i ++) x[i] = fpow(x[i], n);
    DFT(x,  9);
    ull inv = fpow(5, (1ull << 63) - 5);
    for (int i = 0; i < n; ++i)printf("%I64d\n", (x[i].real() >> 5) * inv & ((1ull << 58) - 1));
    return 0;
}