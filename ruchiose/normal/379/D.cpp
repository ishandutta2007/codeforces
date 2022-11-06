// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
#define mp make_pair
using namespace std;

int K, X, N, M;

struct Str
{
    int Sub;
    int First, Second; // 0, 1, 2
    Str() {}
    Str(int sub, int first, int second)
    {
        Sub = sub;
        First = first; Second = second;
    }
    Str operator + (Str Snd)
    {
        Str Ret;
        Ret.First = First;
        Ret.Second = Snd.Second;
        Ret.Sub = min(X + 1, Sub + Snd.Sub + (((Second == 1) && (Snd.First == 2)) ? 1 : 0));
        return Ret;
    }
} S[51];

void Op(Str a, int L)
{
    int C = 0, i;
    if (a.First == 0)
        {
            printf("J");
            C = 1;
        }
    if (a.First == 2)
        {
            printf("C");
            C = 1;
        }
    fortodo(i, 1, a.Sub)
        {
            printf("AC");
            C += 2;
        }
    while (C < L - 1)
        {
            printf("J");
            C++;
        }
    if (C != L)
        {
            if (a.Second == 0) printf("J");
            if (a.Second == 1) printf("A");
            if (a.Second == 2) printf("C");
        }
    printf("\n");
}

void Finish()
{
    Op(S[1], N);
    Op(S[2], M);
    exit(0);
}

int Nf, Ns, Mf, Ms, Nc, Mc, Na, Ma, i;

int main()
{
    scanf("%d%d%d%d", &K, &X, &N, &M);
    fortodo(Nf, 0, 2)
        fortodo(Ns, 0, 2)
            {
                if ((Nf != Ns) && (N == 1)) continue;
                Na = N - 2 + ((Nf == 1) ? 1 : 0) + ((Ns == 2) ? 1 : 0);
                Na = max(Na / 2, 0);
                fortodo(Nc, 0, Na)
                    {
                        S[1] = Str(Nc, Nf, Ns);
                        fortodo(Mf, 0, 2)
                            fortodo(Ms, 0, 2)
                                {
                                    if ((Mf != Ms) && (M == 1)) continue;
                                    Ma = M - 2 + ((Mf == 1) ? 1 : 0) + ((Ms == 2) ? 1 : 0);
                                    Ma = max(Ma / 2, 0);
                                    fortodo(Mc, 0, Ma)
                                        {
                                            S[2] = Str(Mc, Mf, Ms);
                                            fortodo(i, 3, K)
                                                S[i] = S[i - 2] + S[i - 1];
                                            if (S[K].Sub == X)
                                                Finish();
                                        }
                                }
                    }
            }
    printf("Happy new year!\n");
    return 0;
}