#include <cstdio>

int tn, n;

int main() {
    for (scanf("%d", &tn); tn; tn--) { scanf("%d", &n); printf("%d\n", n % 2 == 0 ? n / 2 : 1 + (n - 3) / 2); }
    return 0;
}