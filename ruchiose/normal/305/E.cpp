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

int N, sg[5050];
char ch[5050];
bool E[5050];
int L[5050], R[5050];

int main()
{
    scanf("%s", ch);
    N = strlen(ch);
    sg[0] = 0;
    int i;
    fortodo(i, 1, N)
        {
            int woShiSet = 0;
            int j;
            fortodo(j, 1, i)
                woShiSet |= 1 << (sg[max(0, j - 2)] ^ sg[max(0, i - j - 1)]);
            sg[i] = __builtin_ctz(woShiSet + 1);
        }
    fortodo(i, 0, N - 1)
        E[i] = ((i > 0) && (i < N - 1) && (ch[i - 1] == ch[i + 1]));
    fortodo(i, 0, N - 1)
        if (!E[i])
            L[i] = -1;
        else
            if (E[i - 1])
                L[i] = L[i - 1];
            else
                L[i] = i;
    for (i = N - 1; i >= 0; i--)
        if (!E[i])
            R[i] = -1;
        else
            if (E[i + 1])
                R[i] = R[i + 1];
            else
                R[i] = i;
    int totSG = 0;
    fortodo(i, 0, N - 1)
        if (L[i] == i)
            totSG ^= sg[R[i] - L[i] + 1];
    if (totSG == 0)
        {
            printf("Second\n");
            return 0;
        }
    printf("First\n");
    fortodo(i, 0, N - 1)
        if ((E[i]) && (totSG == (sg[R[i] - L[i] + 1] ^ sg[max(L[i] - 1, i - 2) - L[i] + 1] ^ sg[R[i] - min(R[i] + 1, i + 2) + 1])))
            {
                printf("%d\n", i + 1);
                return 0;
            }
}