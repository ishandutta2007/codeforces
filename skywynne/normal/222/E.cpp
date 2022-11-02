#include<bits/stdc++.h>
using namespace std;
const int N = 60, Mod = 1e9 + 7;
int m, k, c, DEF[N][N];
long long n;
char C[2];
struct Matrix
{
    int n, m, A[N][N];
    Matrix (int nn, int mm, int AA[N][N] = DEF)
    {
        n = nn; m = mm;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                A[i][j] = AA[i][j];
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
        long long tmp = pw;
        while (tmp)
        {
            if (tmp & 1)
                R = R * T;
            T = T * T;
            tmp >>= 1;
        }
        return (R);
    }
    inline void operator ^= (const long long &pw)
    {
        memcpy(A, (Matrix(n, m, A) ^ pw).A, sizeof(A));
    }
    void Prnt()
    {
        for (int i = 0; i < n; i++, puts(""))
            for (int j = 0; j < m; j++)
                printf("%d ", A[i][j]);
    }
};
int get(char ch)
{
    if (ch <= 'Z')
        return (ch - 'A' + 26);
    return (ch - 'a');
}
int main()
{
    scanf("%I64d%d%d", &n, &m, &k);
    Matrix M = Matrix(m, m), T = Matrix(1, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            M.A[i][j] = T.A[0][j] = 1;
    while (k --)
        scanf("%s", &C), M.A[get(C[0])][get(C[1])] = 0;
    M ^= n - 1; T *= M;
    for (int i = 0; i < m; i++)
        c = (c + T.A[0][i]) % Mod;
    return !printf("%d", c);
}