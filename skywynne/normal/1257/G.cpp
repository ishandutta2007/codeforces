// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int LG = 18, N = 1 << LG, Mod = 998244353;
inline int Power(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = 1LL * a * a % Mod)
        if (b & 1) ret = 1LL * ret * a % Mod;
    return (ret);
}
inline int Rev(int a, int k)
{
    int rt = 0;
    for (; k; k --)
        rt = (rt << 1) | (a & 1), a >>= 1;
    return (rt);
}
inline void NTT(vector < int > &F, bool inv = 0)
{
    int n = (int)F.size();
    int k = __builtin_ctz(n);
    for (int i = 0; i < n; i ++)
        if (i < Rev(i, k))
            swap(F[i], F[Rev(i, k)]);
    for (int len = 1; len < n; len <<= 1)
    {
        int wn = Power(3, (Mod - 1) / (len << 1));
        if (inv) wn = Power(wn, Mod - 2);
        for (int i = 0; i < n; i += (len << 1))
            for (int j = i, w = 1; j < i + len; j ++)
            {
                int a = 1LL * F[j + len] * w % Mod;
                F[j + len] = F[j] - a; F[j] += a;
                if (F[j + len] < 0)
                    F[j + len] += Mod;
                if (F[j] >= Mod)
                    F[j] -= Mod;
                w = 1LL * w * wn % Mod;
            }
    }
    if (inv)
        for (int i = 0, rn = Power(n, Mod - 2); i < n; i ++)
            F[i] = 1LL * F[i] * rn % Mod;
}
inline vector < int > Multiply(vector < int > A, vector < int > B)
{
    int n = (int)A.size() + (int)B.size() - 1, k = 0;
    while ((1 << k) < n)
        k ++;
    n = 1 << k;
    while (A.size() < n)
        A.push_back(0);
    while (B.size() < n)
        B.push_back(0);
    NTT(A, 0); NTT(B, 0);
    for (int i = 0; i < n; i ++)
        A[i] = 1LL * A[i] * B[i] % Mod;
    NTT(A, 1);
    while (A.size() > 1 && !A.back())
        A.pop_back();
    return (A);
}
int n, m;
map < int , int > C;
vector < int > V[N];
vector < int > Solve(int l, int r)
{
    if (r - l < 2)
        return (V[l]);
    return (Multiply(Solve(l, l + r >> 1), Solve(l + r >> 1, r)));
}
int main()
{
    scanf("%d", &n);
    for (int i = 1, a; i <= n; i ++)
        scanf("%d", &a), C[a] ++;
    priority_queue < pair < int , int > > Pq;
    for (auto X : C)
        V[++ m] = vector < int > (X.second + 1, 1);
    return !printf("%d\n", Solve(1, m + 1)[n / 2]);
}