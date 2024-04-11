#include <cstdio>
#include <algorithm>

int K;

int main()
{
    scanf("%d", &K);
    if (K%2) printf("-1\n");
    else {
        for (int z = 0; z < K; z++) {
            for (int y = 0; y < K; y++) {
                for (int x = 0; x < K; x++) {
                    if ((std::min(y, std::min(x, std::min(K-y-1, K-x-1)))+z) % 2 == 1)
                        printf("b");
                    else printf("w");
                }
                printf("\n");
            }
            printf("\n");
        }
    }
}