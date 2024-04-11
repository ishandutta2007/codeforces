#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {
    scanf("%d %d %d", &a, &b, &c);
    printf("%lld\n", 2ll * c + min(2 * min(a, b) + 1, a + b));

    return 0;
}