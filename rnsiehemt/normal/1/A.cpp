#include <cstdio>

long long N, M, A;

int main()
{
    scanf("%I64d%I64d%I64d", &N, &M, &A);
    printf("%I64d\n", ((N+A-1)/A)*((M+A-1)/A));
}