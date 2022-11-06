#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int main()
{
    int N, s = 0, i, u;
    scanf("%d", &N);
    fortodo(i, 1, N) s ^= i;
    fortodo(i, 2, N)
        {
            scanf("%d", &u);
            s ^= u;
        }
    printf("%d\n", s);
}