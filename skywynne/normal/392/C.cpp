#include<bits/stdc++.h>
#pragma GCC optimize ("unroll-loops")
using namespace std;
const int N = 88, Mod = 1e9 + 7;
int DEF[N][N];
struct Matrix
{
    int n, m, A[N][N];
    Matrix (int nn, int mm, int AA[N][N] = DEF)
    {
        n = nn; m = mm; memcpy(A, AA, sizeof(A));
    }
    inline Matrix operator * (const Matrix &X)
    {
        Matrix T = Matrix(n, X.m);
        for (int i = 0; i < T.n; i++)
            for (int j = 0; j < X.m; j++)
                for (int h = 0; h < m; h++)
                    T.A[i][j] = (T.A[i][j] + 1ll * A[i][h] * X.A[h][j]) % Mod;
        return (T);
    }
    inline void operator *= (const Matrix &Y)
    {
        memcpy(A, (Matrix(n, m, A) * Y).A, sizeof(A));
    }
    inline Matrix operator ^ (const long long &pw)
    {
        Matrix R = Matrix(n, m);
        for (int i = 0; i < n; i++)
            R.A[i][i] = 1;
        Matrix T = Matrix(n, m, A);
        for (long long tmp = pw; tmp; tmp >>= 1, T = T * T)
            if (tmp & 1)
                R = R * T;
        return (R);
    }
    inline void operator ^= (const long long &pw)
    {
        memcpy(A, (Matrix(n, m, A) ^ pw).A, sizeof(A));
    }
};
inline int Power(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = 1ll * a * a % Mod)
        if (b & 1) ret = 1ll * ret * a % Mod;
    return (ret);
}
long long n, k, C[N][N];
int main()
{
    scanf("%lld%lld", &n, &k); k ++;
    for (int i = 0; i < N; i++)
        for (int j = C[0][i] = C[i][i] = 1; j < i; j++)
            C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % Mod;
    Matrix A = Matrix(1, 2 * k + 1);
    for (int i = 0; i < k; i++)
        A.A[0][i] = 1, A.A[0][i + k] = Power(2, i + 1) % Mod;
    A.A[0][k * 2] = (A.A[0][k - 1] + A.A[0][k * 2 - 1]);
    Matrix M = Matrix(2 * k + 1, 2 * k + 1);
    for (int i = 0; i < k; i++)
        M.A[i + k][i] = 1;
    for (int i = 0; i < k; i++)
        for (int j = 0; j <= i; j++)
            M.A[j][i + k] = 1ll * Power(2, i - j) * C[j][i] % Mod, M.A[j + k][i + k] = C[j][i];
    M.A[k * 2][k * 2] = 1;
    for (int j = 0; j < k; j++)
        M.A[j][k * 2] = 1ll * Power(2, k - 1 - j) * C[j][k - 1] % Mod, M.A[j + k][k * 2] = C[j][k - 1];
    if (n == 1) return !printf("1");
    A = A * (M ^ (n - 2));
    return !printf("%d", A.A[0][k * 2]);
}