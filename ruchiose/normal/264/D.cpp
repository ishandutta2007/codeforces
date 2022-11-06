// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

char S_[1000010], T_[1000010];
int S[1000010], T[1000010];
int Snxt[3][1000010], Tnxt[3][1000010];
int SLeastT[1000010], TLeastS[1000010];
int ScontT[1000010], TsumSect[1000010][9];

void Process(char* ch, int* a)
{
    a[0] = strlen(ch);
    int i;
    fortodo(i, 0, a[0] - 1)
        a[i + 1] = (ch[i] == 'R') ? 0 : ((ch[i] == 'G') ? 1 : 2);
}

void makeNxt(int* a, int* nxt, int c)
{
    nxt[a[0] + 1] = a[0] + 1;
    for (int i = a[0]; i; i--)
        if (a[i] == c)
            nxt[i] = i;
        else
            nxt[i] = nxt[i + 1];
}

int main()
{
    scanf("%s", S_ + 1); Process(S_ + 1, S);
    scanf("%s", T_ + 1); Process(T_ + 1, T);
    int i, j;
    fortodo(i, 0, 2)
        {
            makeNxt(S, Snxt[i], i);
            makeNxt(T, Tnxt[i], i);
        }
    SLeastT[0] = 0;
    fortodo(i, 1, S[0])
        if (SLeastT[i - 1] > T[0])
            SLeastT[i] = T[0] + 1;
        else
            SLeastT[i] = Tnxt[S[i]][SLeastT[i - 1] + 1];
    TLeastS[0] = 0;
    fortodo(i, 1, T[0])
        if (TLeastS[i - 1] > S[0])
            TLeastS[i] = S[0] + 1;
        else
            TLeastS[i] = Snxt[T[i]][TLeastS[i - 1] + 1];
    ScontT[0] = 0;
    fortodo(i, 1, S[0])
        {
            ScontT[i] = ScontT[i - 1];
            if ((ScontT[i] != T[0]) && (TLeastS[ScontT[i] + 1] == i)) ScontT[i]++;
        }
    fortodo(i, 0, 8)
        TsumSect[0][i] = TsumSect[1][i] = 0;
    fortodo(i, 2, T[0])
        {
            fortodo(j, 0, 8)
                TsumSect[i][j] = TsumSect[i - 1][j];
            TsumSect[i][T[i - 1] * 3 + T[i]]++;
        }
    i64 ans = 0;
    fortodo(i, 1, S[0])
        {
            int R = min(SLeastT[i], T[0]);
            int L = ScontT[i - 1] + 1;
            ans += R - L + 1;
            if ((i > 1) && (S[i] != S[i - 1]))
                ans -= TsumSect[R][S[i] * 3 + S[i - 1]] - TsumSect[L - 1][S[i] * 3 + S[i - 1]];
        }
    cout << ans << endl;
}