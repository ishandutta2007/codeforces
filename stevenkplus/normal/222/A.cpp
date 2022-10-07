#include <cstdio>

using namespace std;
const int MAXN = 100100;
int N, K;
int ar[MAXN];
int main() {
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i) {
        scanf("%d", ar + i);
    }
    int m = ar[K - 1];
    for(int i = K; i < N; ++i) {
        if (ar[i] != m) {
            printf("-1\n");
            return 0;
        }
    }
    int i = K - 2;
    while (ar[i] == m && i >= 0) {
        i--;
    }
    int num = i - 0 + 1;
    printf("%d\n", num);
    return 0;
}