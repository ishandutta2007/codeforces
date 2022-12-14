#include <bits/stdc++.h>

using namespace std;

main() {
    puts("2000");
    for (int i = 1; i <= 1000; i ++) {
        printf("%d 1 %d 2\n", i, i);
    }
    for (int i = 1000; i; i --) {
        printf("%d 1 %d 2\n", i, i);
    }
}