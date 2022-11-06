#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, L, R, i, A[1001];
int ANS[3];

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d", &A[i]);
    ANS[1] = ANS[2] = 0;
    L = 1; R = N;
    fortodo(i, 1, N)
        {
            if (A[L] > A[R])
                {ANS[i % 2 + 1] += A[L]; L++;}
            else
                {ANS[i % 2 + 1] += A[R]; R--;}
        }
    printf("%d %d\n", ANS[2], ANS[1]);
}