#include <bits/stdc++.h>
using namespace std;

int k, a, b, c, d;

int main() {
    scanf("%d %d %d", &k, &a, &b);
    c = a / k, d = b / k, a %= k, b %= k;
    if (a && !d || b && !c) return puts("-1"), 0;
    printf("%d\n", c + d);
    return 0;
}