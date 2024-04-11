#include <cstdio>
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    if ((n < m ? n : m) % 2) printf("Akshat\n");
    else printf("Malvika\n");
}