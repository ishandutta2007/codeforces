#include <bits/stdc++.h>
using namespace std;

int x, y, z, a, b, c;

bool solve() {
    scanf("%d %d %d %d %d %d", &x, &y, &z, &a, &b, &c);
    if (x > a) return 0;
    a -= x; y -= a;
    if (y > b) return 0;
    b -= y; z -= b;
    if (z > c) return 0;
    return 1;
}

int main() {
    puts(solve() ? "YES" : "NO");
}