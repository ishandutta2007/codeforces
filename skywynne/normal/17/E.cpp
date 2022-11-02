#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000006, Mod = 51123987;
int n, S[N], E[N];
uint64_t P[N], H[N], R[N];
char A[N];
inline uint64_t GetH(int l, int r)
{
    return (H[r] - H[l - 1] * P[r - l + 1]);
}
inline uint64_t GetR(int l, int r)
{
    return (R[l] - R[r + 1] * P[r - l + 1]);
}
inline int Getodd(int i)
{
    int le = 0, ri = min(i - 1, n - i) + 1, md;
    while (ri - le > 1)
    {
        md = (le + ri) >> 1;
        if (GetH(i - md, i) == GetR(i, i + md))
            le = md;
        else
            ri = md;
    }
    return (le);
}
inline int Geteven(int i)
{
    int le = 0, ri = min(i - 2, n - i) + 1, md;
    while (ri - le > 1)
    {
        md = (le + ri) >> 1;
        if (GetH(i - md - 1, i - 1) == GetR(i, i + md))
            le = md;
        else
            ri = md;
    }
    return (le);
}
int main()
{
    scanf("%d%s", &n, A + 1);
    for (int i = 1; i <= n; i++)
        H[i] = (H[i - 1] + A[i] - 'a' + 1) * 797LL;
    for (int i = n; i; i--)
        R[i] = (R[i + 1] + A[i] - 'a' + 1) * 797LL;
    for (int i = P[0] = 1; i < N; i++)
        P[i] = P[i - 1] * 797LL;
    for (int i = 1; i <= n; i++)
    {
        int len = Getodd(i);
        S[i - len] ++;
        S[i + 1] --;
        E[i] ++;
        E[i + len + 1] --;
        if (i > 1 && A[i] == A[i - 1])
        {
            len = Geteven(i);
            S[i - len - 1] ++;
            S[i] --;
            E[i] ++;
            E[i + len + 1] --;
        }
    }
    int cnt = 0, tot = 0;
    for (int i = 1; i <= n; i++)
    {
        S[i] += S[i - 1];
        E[i] += E[i - 1];
        cnt += S[i];
        if (cnt >= Mod)
            cnt -= Mod;
        cnt -= E[i];
        if (cnt < 0)
            cnt += Mod;
        tot = (tot + ((long long)E[i] * (E[i] - 1 + cnt + cnt) >> 1)) % Mod;
    }
    return !printf("%d\n", tot);
}