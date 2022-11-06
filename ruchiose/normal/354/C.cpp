#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXA = 1000000;
const int Container = 1000010;

int N, K, Diff[Container], C[Container];

int main()
{
    scanf("%d%d", &N, &K);
    int i, j;
    int mina = MAXA;
    fortodo(i, 0, MAXA) Diff[i] = 0;
    fortodo(i, 1, N)
        {
            int ai;
            scanf("%d", &ai);
            mina = min(mina, ai);
            Diff[max(1, ai - K)]++; Diff[ai + 1]--;
        }
    // Re difference
    C[0] = 0;
    fortodo(i, 1, MAXA)
        C[i] = C[i - 1] + Diff[i];
    for (i = mina; i; i--)
        {
            int t = 0;
            for (j = i; j <= MAXA; j += i)
                t += C[j];
            if (t >= N)
                {
                    printf("%d\n", i);
                    return 0;
                }
        }
}