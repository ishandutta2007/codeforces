#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    if (N % 2 == 0)
        {
            printf("-1\n");
            return 0;
        }
    int i;
    fortodo(i, 0, N - 1) printf("%d%s", i, (i == N - 1) ? "\n" : " ");
    fortodo(i, 0, N - 1) printf("%d%s", i, (i == N - 1) ? "\n" : " ");
    fortodo(i, 0, N - 1) printf("%d%s", i * 2 % N, (i == N - 1) ? "\n" : " ");  
}