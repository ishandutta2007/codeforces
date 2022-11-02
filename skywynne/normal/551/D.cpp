#include<bits/stdc++.h>
using namespace std;
const int N = 2;
int DEF[N][N];
long long n, k, l, NX, r, t, c;
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
int main()
{
    scanf("%I64d%I64d%I64d%I64d", &n, &k, &l, &NX);
    if (l < 60 && (1ll << l) <= k)
        return !printf("0");
    Matrix M = Matrix(2, 2); M.A[0][1] = M.A[1][0] = M.A[1][1] = 1; M ^= n;
    Matrix P = Matrix(1, 1); P.A[0][0] = 2; P ^= n;
    r = (M.A[1][0] + M.A[1][1]) % NX; c = 1;
    t = (P.A[0][0] - r + NX) % NX;
    while (l > 60)
        c = c * r % NX, l--;
    for (int i = 0; i < l; i++)
    {
        if (k & (1ll << i))
            c = c * t % NX;
        else
            c = c * r % NX;
    }
    return !printf("%I64d", c % NX);
}