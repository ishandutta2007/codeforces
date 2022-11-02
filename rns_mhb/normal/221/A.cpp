#include<stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);
    printf("%d", n);
    for(i = 1; i < n; i ++) printf(" %d", i);
}