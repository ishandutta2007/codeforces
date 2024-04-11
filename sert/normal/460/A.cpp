#include <cstdio>
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i != -1; i++) {
        if (n <= 0) {printf("%d", i); i = -2;}
        else if (i % m == m - 1) n++;
        n--;
    }
}