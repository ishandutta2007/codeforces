#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, i, j, A[101], B[101];

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d%d", &A[i], &B[i]);
    int ans = 0;
    fortodo(i, 1, N)
        {
            fortodo(j, 1, N)
                if ((i != j) && (A[i] == B[j]))
                    break;
            if (j > N) ans++;
        }
    printf("%d\n", ans);
}