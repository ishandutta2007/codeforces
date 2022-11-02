#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    for(int i = 0; i < b; i ++) {
        int k = a * i;
        if(k > c) break;
        k = c - k;
        if(k % b == 0){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}