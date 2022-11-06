// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const i64 P = 998244353;
const i64 G = 3;

i64 Qipow(i64 b, i64 t, i64 p = P)
{
    i64 r = 1;
    for (; t; t >>= 1)
        {
            if (t & 1) r = (r * b) % p;
            b = (b * b) % p;
        }
    return r;
}

int N, M, A[1000010], Raw[1<<21], F;
int bitrev[1<<21];
i64 S[1<<21], omega[(1<<21)+1];

void Reorder()
{
    int i;
    fortodo(i, 0, F - 1)
        if (i < bitrev[i])
            swap(S[i], S[bitrev[i]]);
}

void Butterfly(i64 &a, i64 &b, i64 w)
{
    i64 ta = (a + b * w) % P, tb = (a + (P - b) * w) % P;
    a = ta; b = tb;
}

void FFT()
{
    for (int L = 2; L <= F; L <<= 1)
        for (int i = 0; i < F; i += L)
            for (int j = 0; j < L / 2; j++)
                Butterfly(S[i + j], S[i + j + L / 2], omega[j * (F / L)]);
}

void iButterfly(i64 &a, i64 &b, i64 w)
{
    i64 ta = ((a + b) * (P + 1) / 2) % P;
    i64 tb = (((a - b) * (P + 1) / 2) % P * w) % P;
    a = ta; b = tb;
}

void iFFT()
{
    for (int L = F; L >= 2; L >>= 1)
        for (int i = 0; i < F; i += L)
            for (int j = 0; j < L / 2; j++)
                iButterfly(S[i + j], S[i + j + L / 2], omega[F - j * (F / L)]);
}

vector<int> VI;

int main()
{
    scanf("%d%d", &N, &M);
    int i;
    F = M * 2 - 1;
    while (F != (F & (-F))) F += (F & -F);
    fortodo(i, 0, F - 1) S[i] = Raw[i] = 0;
    omega[0] = 1; omega[1] = Qipow(G, (P - 1) / F);
    fortodo(i, 2, F) omega[i] = (omega[i - 1] * omega[1]) % P;
    fortodo(i, 1, N)
        {
            scanf("%d", &A[i]);
            S[A[i]] = Raw[A[i]] = 1;
        }
    bitrev[0] = 0;
    fortodo(i, 1, F - 1)
        if (i & 1)
            bitrev[i] = bitrev[i - 1] + (F >> 1);
        else
            bitrev[i] = bitrev[i >> 1] >> 1;
    Reorder();
    FFT();
    fortodo(i, 0, F - 1) S[i] = S[i] * S[i] % P;
    iFFT();
    Reorder();
    fortodo(i, 1, M)
        if ((S[i]) && (!Raw[i]))
            {
                printf("NO\n");
                return 0;
            }   
    VI.clear();
    fortodo(i, 1, M)
        if ((!S[i]) && (Raw[i]))
            VI.push_back(i);
    printf("YES\n%d\n", VI.size());
    for (vector<int>::iterator it = VI.begin(); it != VI.end(); it++)
        printf("%d%s", *it, (it + 1 == VI.end()) ? "\n" : " ");
}