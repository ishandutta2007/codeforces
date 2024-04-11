#include <bits/stdc++.h>
using namespace std;
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define N 105
const int mod = 1e9 + 7;

char s[N];

int h[N], f[N][2];

int n, x;

struct Mat {
    int a[N][N];
    Mat () {memset(a, 0, sizeof a);}
    Mat operator * (const Mat &b) const {
        Mat res;
        for (int i = 0; i <= n+1; i ++)
        for (int j = 0; j <= n+1; j ++)
        for (int k = 0; k <= n+1; k ++) res.a[i][j] = (res.a[i][j] + 1ll * a[i][k] * b.a[k][j]) % mod;
        return res;
    }
} A[2], B;

int main() {
    scanf("%d %d", &n, &x);
    scanf("%s", s+1);
    f1(i, 1, n+1) s[i] -= '0';
    h[1] = 0;
    for (int i = 2, j = 0; i <= n; i ++) {
        while (j && s[i] != s[j+1]) j = h[j];
        if (s[j+1] == s[i]) j ++;
        h[i] = j;
    }
    f1(i, 0, n) {
        f0(j, 0, 2) {
            if (s[i+1] == j) f[i][j] = i+1;
            else f[i][j] = f[h[i]][j];
        }
    }
    f0(i, 0, 2) {
		f1(j, 0, n) {
            A[i].a[j][j] = 1;
            A[i].a[j][f[j][i]] += 1;
		}
        if (s[n] == i) {
            f1(j, 0, n) A[i].a[j][n+1] += A[i].a[j][n];
			A[i].a[n][n+1] --;
        }
        A[i].a[n+1][n+1] = 2;
    }
    if (x == 0) {
        printf("%d\n", A[0].a[0][n+1]);
        return 0;
    }
    f1(i, 2, x) {
        B = A[1] * A[0];
        swap(A[0], A[1]);
        swap(A[1], B);
    }
    printf("%d\n", A[1].a[0][n+1]);
}