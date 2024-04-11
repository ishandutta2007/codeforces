#include <cstdio>

char s[][10] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
int N;

int main()
{
    scanf("%d", &N); N;
    while (N > 5) N = N/2-2;
    printf("%s\n", s[N-1]);
}