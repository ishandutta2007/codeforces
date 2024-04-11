#include <cstdio>
#include <algorithm>

int N, M;

int main()
{
    scanf("%d%d", &N, &M);
    printf("%s\n", (std::min(N, M) % 2 == 1) ? "Akshat" : "Malvika");
}