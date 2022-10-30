#include <cstdio>
#include <algorithm>

int N, S, A;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a, b; scanf("%d%d", &a, &b);
        S += b-a;
        A = std::max(A, S);
    }
    printf("%d\n", A);
}