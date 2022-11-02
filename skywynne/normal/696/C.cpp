#include<bits/stdc++.h>
using namespace std;
const int N = 2, NX = 1e9 + 7;
int n, t = 2, DEF[N][N];
long long r;
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
    Matrix operator * (const Matrix &X)
    {
        Matrix T = Matrix(n, m);
        for (int i = 0; i < T.n; i++)
            for (int j = 0; j < T.m; j++)
                for (int h = 0; h < m; h++)
                    T.A[i][j] = (T.A[i][j] + 1ll * A[i][h] * X.A[h][j]) % NX;
        return (T);
    }
    void operator *= (const Matrix &Y)
    {
        Matrix X = Matrix(n, m, A);
        Matrix T = X * Y;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                A[i][j] = T.A[i][j];
    }
    Matrix operator ^ (const long long vp)
    {
        Matrix R = Matrix(n, m);
        for (int i = 0; i < n; i++)
            R.A[i][i] = 1;
        Matrix T = Matrix(n, m, A);
        long long tmp = vp;
        while (tmp)
        {
            if (tmp & 1)
                R = R * T;
            T = T * T;
            tmp >>= 1;
        }
        return (R);
    }
    void operator ^= (const long long vp)
    {
        Matrix T = Matrix(n, m, A);
        T = T ^ vp;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                A[i][j] = T.A[i][j];
    }
    void Prnt()
    {
        for (int i = 0; i < n; i++, putchar('\n'))
            for (int j = 0; j < m; j++)
                printf("%d ", A[i][j]);
    }
};
long long Power(long long a, long long b)
{
    if (b == 0)
        return (1);
    long long tmp = Power(a, b / 2);
    tmp = tmp * tmp % NX;
    if (b & 1)
        tmp = tmp * a % NX;
    return (tmp);
}
int main()
{
    scanf("%d", &n);
    Matrix M = Matrix(2, 2);
    M.A[0][0] = M.A[1][0] = 1; M.A[0][1] = 2;
    while (n --)
        scanf("%I64d", &r), M ^= r, t = Power(t, r) % NX;
    t = t * Power(2, NX - 2) % NX; M.A[1][1] = M.A[1][1] * Power(2, NX - 2) % NX;
    if (M.A[1][1] == 0)
        t = 1;
    printf("%d/%d", M.A[1][1], t);
}