#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e6 + 10, NX = 1e9 + 7;
int n, r, t, p;
long long c, Fact[MXN], Inv[MXN];
char A[MXN], B[MXN];
int Power(int a, int b)
{
    if (b == 0)
        return (1);
    long long tt = Power(a, b / 2);
    tt = (tt * tt) % NX;
    if (b & 1)
        tt = (tt * a) % NX;
    return ((int)tt);
}
int Smaller(char T[])
{
    int C[26];
    long long res = 0;
    for (int i = 0; i < 26; i++)
        C[i] = 0;
    for (int i = 0; i < n; i++)
        C[A[i] - 'a'] ++;
    for (int i = 0; i < n; i++)
    {
        long long cc = Fact[n - i - 1], rr = 1, tt;
        for (int j = 0; j < 26; j++)
            rr = (rr * Inv[C[j]]) % NX;
        for (int j = 0; j < T[i] - 'a'; j++)
        {
            if (C[j] == 0)
                continue;
            tt = (rr * Fact[C[j]]) % NX;
            tt = (tt * Inv[C[j] - 1]) % NX;
            res = (res + (cc * tt)) % NX;
        }
        if (C[T[i] - 'a'] == 0)
            break;
        C[T[i] - 'a'] --;
    }
    return ((int)res);
}
int main()
{
    Fact[0] = 1;
    for (int i = 1; i <= 1e6; i++)
        Fact[i] = (Fact[i - 1] * i) % NX;
    for (int i = 0; i <= 1e6; i++)
        Inv[i] = Power(Fact[i], NX - 2);
    scanf("%s%s", &A, &B);
    n = strlen(A);
    r = Smaller(A);
    t = Smaller(B);
    c = (t - r - 1 + NX) % NX;
    printf("%I64d", (c + NX) % NX);
    return (0);
}