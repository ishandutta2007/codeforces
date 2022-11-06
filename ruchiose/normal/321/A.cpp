#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int A, B, N, i, j;
char S[110];
int D[110][2];

bool Istarg(int a, int b, int aa, int bb)
{
    if ((b) ? (a % b) : (a)) return false;
    if ((bb) ? (aa % bb) : (aa)) return false;
    if ((b == 0) && (bb == 0))
        return ((aa == 0) && (a == 0));
    if (b == 0) return (aa / bb >= 0);
    if (bb == 0) return (a / b >= 0);
    return ((a / b == aa / bb) && (a / b >= 0));
}

int main()
{
    scanf("%d%d%s", &A, &B, S + 1);
    N = strlen(S + 1);
    D[0][0] = D[0][1] = 0;
    fortodo(i, 1, N)
        {
            D[i][0] = D[i - 1][0];
            D[i][1] = D[i - 1][1];
            if (S[i] == 'U') D[i][1]++;
            if (S[i] == 'D') D[i][1]--;
            if (S[i] == 'R') D[i][0]++;
            if (S[i] == 'L') D[i][0]--;
        }
    fortodo(i, 0, N - 1)
        if ((Istarg(A - D[i][0], D[N][0], B - D[i][1], D[N][1])))
            {
                printf("Yes\n");
                return 0;
            }
    printf("No\n");
}