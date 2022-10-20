#include<iostream>
#include<stdio.h>

int main(){
    int n;

    scanf("%d", &n);

    if (n % 4 == 2 || n % 4 == 3) {
        printf("-1\n");
        return 0;
    }

    for (int i = 1, len = n >> 1; i < len; i += 2)
        printf("%d %d ", i+1, n - i + 1);

    if (n % 2)
        printf("%d ", (n >> 1) + 1);

    for (int i = (n >> 1) - 1; i > 0; i -= 2)
        printf("%d %d\n", i, n - i);


    return 0;
}