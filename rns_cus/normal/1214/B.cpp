#include <bits/stdc++.h>
using namespace std;

#define N

int n, b, g;

int main() {
    scanf("%d %d %d", &b, &g, &n);
    int mn = max(0, n - g), mx = min(n, b);
    printf("%d\n", mx - mn + 1);


    return 0;
}