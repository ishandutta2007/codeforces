#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, i, j, X, Y, Ans;
bool R[1001], C[1001];

int CALC(bool R1, bool R2, bool C1, bool C2)
{
    int i, j, k, l, Ans, Subans;
    Ans = 0;
    fortodo(i, 0, 2) if ((i == 0) || (R1))
    fortodo(j, 0, 2) if ((j == 0) || (R2))
    fortodo(k, 0, 2) if ((k == 0) || (C1))
    fortodo(l, 0, 2) if ((l == 0) || (C2))
        {
            if ((i == 1) && (k == 1)) continue;
            if ((i == 1) && (l == 2)) continue;
            if ((i == 2) && (k == 2)) continue;
            if ((i == 2) && (l == 1)) continue;
            if ((j == 1) && (l == 1)) continue;
            if ((j == 1) && (k == 2)) continue;
            if ((j == 2) && (l == 2)) continue;
            if ((j == 2) && (k == 1)) continue;
            Subans = 0;
            if (i > 0) Subans++;
            if (j > 0) Subans++;
            if (k > 0) Subans++;
            if (l > 0) Subans++;
            Ans = max(Ans, Subans);
        };
    return Ans;
};

int main()
{
    scanf("%d%d", &N, &M);
    fortodo(i, 1, N) R[i] = C[i] = true;
    fortodo(i, 1, M)
        {
            scanf("%d%d", &X, &Y);
            R[X] = false;
            C[Y] = false;
        };
    if (N % 2 == 1) Ans = ((R[(N + 1) / 2]) || (C[(N + 1) / 2])) ? 1 : 0;
    fortodo(i, 2, (N / 2)) Ans += CALC(R[i], R[N + 1 - i], C[i], C[N + 1 - i]);
    printf("%d\n", Ans);
    return 0;
};