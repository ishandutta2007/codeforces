#include <bits/stdc++.h>

using namespace std;

main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    for (int i = 0; a * i <= c; i ++) {
        int j = (c - a * i) / b;
        if (c == a * i + b * j) return puts("Yes");
    }
    puts("No");
}