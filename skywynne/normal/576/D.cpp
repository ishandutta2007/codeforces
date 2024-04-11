// In The Name Of The Queen
#include<bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
using namespace std;
const int N = 153, LG = 31;
struct Matrix
{
    int n, m;
    bitset < N > A[N], B[N];
    inline Matrix(int _n = 0, int _m = 0)
    {
        n = _n; m = _m;
        for (int i = 0; i < N; i ++)
            A[i] = B[i] = 0;
    }
    inline Matrix operator * (Matrix &X)
    {
        Matrix R(n, X.m);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                R.A[i][j] = R.B[j][i] = (A[i] & X.B[j]).count() > 0;
        return (R);
    }
    inline Matrix operator ^ (long long Pw)
    {
        Matrix T = * this, R(n, n);
        for (int i = 0; i < n; i ++)
            R.A[i][i] = R.B[i][i] = 1;
        for (; Pw; Pw >>= 1, T = T * T)
            if (Pw & 1) R = R * T;
        return (R);
    }
};
int n, m, A[N], B[N], D[N], P[N];
inline bool CMP(int i, int j)
{
    return (D[i] < D[j]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        scanf("%d%d%d", &A[i], &B[i], &D[i]);
        A[i] --, B[i] --;
        if (A[i] == n - 1)
            i --, m --;
    }
    iota(P + 1, P + m + 1, 1);
    sort(P + 1, P + m + 1, CMP);
    Matrix F(1, n), M(n, n), TMP;
    F.A[0][0] = F.B[0][0] = 1;
    M.A[n - 1][n - 1] = M.B[n - 1][n - 1] = 1;
    int Pw = -1;
    P[m + 1] = m + 1; D[m + 1] = 1e9 + N;
    for (int i = 1; i <= m + 1; i ++)
    {
        TMP = M ^ (D[P[i]] - D[P[i - 1]]);
        TMP = F * TMP;
        if (TMP.A[0][n - 1] == 1)
            {Pw = D[P[i - 1]]; break;}
        if (i > m)
            return !printf("Impossible\n");
        F = TMP;
        int a = A[P[i]], b = B[P[i]];
        M.A[a][b] = M.B[b][a] = 1;
    }
    Matrix PW[LG]; PW[0] = M;
    for (int i = 1; i < LG; i ++)
        PW[i] = PW[i - 1] * PW[i - 1];
    for (int i = LG - 1; ~ i; i --)
    {
        TMP = F * PW[i];
        if (TMP.A[0][n - 1] == 0)
            Pw += 1 << i, F = TMP;
    }
    return !printf("%d\n", Pw + 1);
}