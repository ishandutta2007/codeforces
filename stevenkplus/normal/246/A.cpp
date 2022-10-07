#include <cstdio>

using namespace std;

int N;
int main() {
    scanf("%d", &N);
    if (N <= 2) {
        printf("-1\n");
    } else {
        printf("2 2");
        for(int i = 2; i < N; ++i) {
            printf(" 1");
        }
    }
    return 0;
}