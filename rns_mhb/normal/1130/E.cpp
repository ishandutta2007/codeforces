#include<bits/stdc++.h>
using namespace std;

int main() {
    int k, x = 500, y, s;
    scanf("%d", &k);
    y = 1000 - k % x;
    s = (k + y) / x + 1;
    printf("%d\n", x + y);
    for(int i = 1; i < x; i ++) printf("0 ");
    printf("-1 ");
    for(int i = 1; i <= y; i ++) {
        if(s > 1000000) {
            printf("1000000 ");
            s -= 1000000;
        }
        else {
            printf("%d ", s);
            s = 0;
        }
    }
    puts("");
}