#include <cstdio>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i <= N; ++i) {
        if (i * (i + 1) / 2 == N) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}