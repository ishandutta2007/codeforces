#include <cstdio>

int main()
{
    int N; scanf("%d", &N);
    printf("%s\n", ((N%2) == 0 && N >= 4 ? "YES" : "NO"));
}