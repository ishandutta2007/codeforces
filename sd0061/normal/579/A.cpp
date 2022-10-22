#include <cstdio>
int main() {
    int x;
    scanf("%d" , &x);
    printf("%d" , (int)__builtin_popcount(x));
    return 0;
}