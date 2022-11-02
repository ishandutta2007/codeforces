#include<bits/stdc++.h>
using namespace std;
const int N = 202, SGM = 26;
int n, ts = 1, A[N], C[N][SGM], Ac[N], Suf[N], Qu[N], F[N];
long long len;
char S[N];
struct Matrix
{
    int n, m;
    long long A[N][N];
    Matrix (int nn, int mm)
    {
        n = nn; m = mm; memset(A, -63, sizeof(A));
    }
    inline Matrix operator * (const Matrix &X)
    {
        Matrix T = Matrix(n, X.m);
        for (int i = 0; i < T.n; i++)
            for (int j = 0; j < X.m; j++)
                for (int h = 0; h < m; h++)
                    T.A[i][j] = max(T.A[i][j], A[i][h] + X.A[h][j]);
        return (T);
    }
    inline Matrix operator ^ (const long long &pw)
    {
        Matrix R = Matrix(n, m);
        for (int i = 0; i < n; i++)
            R.A[i][i] = 0;
        Matrix T = * this;
        for (long long tmp = pw; tmp; tmp >>= 1, T = T * T)
            if (tmp & 1)
                R = R * T;
        return (R);
    }
};
inline void Add(char * _S, int k)
{
    int i = 0, id = 0;
    while (_S[i])
    {
        if (!C[id][_S[i] - 'a'])
            C[id][_S[i] - 'a'] = ts ++;
        id = C[id][_S[i] - 'a']; i++;
    }
    Ac[id] = 1;
    F[id] += A[k];
}
inline void BFS()
{
    int l = 0, r = 0, id;
    for (int i = 0; i < SGM; i++)
        if (C[0][i])
            Qu[r ++] = C[0][i];
    while (r - l)
    {
        id = Qu[l ++];
        for (int i = 0; i < SGM; i++)
        {
            if (!C[id][i])
                C[id][i] = C[Suf[id]][i];
            else
                Qu[r ++] = C[id][i], Suf[C[id][i]] = C[Suf[id]][i];
        }
        if (Suf[id] && !Ac[Suf[id]])
            Suf[id] = Suf[Suf[id]];
        F[id] += F[Suf[id]];
    }
}
int main()
{
    scanf("%d%lld", &n, &len);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &S); Add(S, i);
        fill(S, S + strlen(S), 0);
    }
    BFS();
    Matrix M(ts, ts);
    for (int i = 0; i < ts; i++)
        for (int j = 0; j < ts; j++)
            for (int h = 0; h < SGM; h++)
                if (C[j][h] == i)
                    M.A[j][i] = F[i];
    Matrix P(1, ts);
    P.A[0][0] = 0;
    M = M ^ len; P = P * M;
    long long Mx = 0;
    for (int i = 0; i < ts; i++)
        Mx = max(Mx, P.A[0][i]);
    return !printf("%lld", Mx);
}