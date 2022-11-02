#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, c;

void go(ll y) {
    printf("%I64d\n", y);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x == 1) a += y;
    else if (x == 2) b += y;
    else if (x == 3) c += y;
    else exit(0);
}

int main() {
    scanf("%I64d %I64d %I64d", &a, &b, &c);
    puts("First");
    fflush(stdout);
    go(1e9);
    ll mx = max(a, max(b, c));
    go(3 * mx - a - b - c);
    ll x = a, y = b;
    if (x > y) swap(x, y);
    if (x < c && c < y) y = c;
    go(y - x);

    return 0;
}