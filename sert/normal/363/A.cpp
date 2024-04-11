#include <cstdio>
void go(int x) {
    if (x >= 5) printf("-O|");
    else printf("O-|");
    for (int i = 0; i < x % 5; i++) printf("O");
    printf("-");
    for (int i = x % 5; i < 4; i++) printf("O");
    printf("\n");
}
int n;
int main() {
    scanf("%d", &n);
    if (n == 0) go(0);
    while (n > 0) {
        go(n % 10);
        n /= 10;
    }
}