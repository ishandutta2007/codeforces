#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, i, j;
int A[101], D[101], S[101];
char typ[5];

int ATK()
{
    int i, j, R = 0;
    for (i = 1, j = S[0]; (i <= A[0]) && (j) && (S[j] >= A[i]); j--, i++)
        R += S[j] - A[i];
    return R;
}

int Us[101];

int DEF()
{   
    int i, j;
    fortodo(i, 1, S[0]) Us[i] = 0;
    fortodo(i, 1, D[0])
        {
            fortodo(j, 1, S[0])
                if ((S[j] > D[i]) && (Us[j] == 0))
                    break;
            if (j > S[0]) return 0;
            Us[j] = 1;
        }
    j = S[0];
    for (i = A[0]; i; i--)
        {
            while ((j) && (Us[j] == 1)) j--;
            if (j == 0) return 0;
            if (S[j] < A[i]) return 0;
            Us[j] = 2;
        }
    int TOT = 0;
    fortodo(i, 1, S[0])
        if (Us[i] != 1)
            TOT += S[i];
    fortodo(i, 1, A[0])
        TOT -= A[i];
    return TOT;
}

int main()
{
    scanf("%d%d", &N, &M); A[0] = D[0] = 0; S[0] = M;
    fortodo(i, 1, N)
        {
            scanf("%s%d", typ + 1, &j);
            if (typ[1] == 'A')
                A[++A[0]] = j;
            else
                D[++D[0]] = j;
        }
    fortodo(i, 1, M) scanf("%d", &S[i]);
    sort(S + 1, S + M + 1);
    sort(A + 1, A + A[0] + 1);
    sort(D + 1, D + D[0] + 1);
    printf("%d\n", max(ATK(), DEF()));
}