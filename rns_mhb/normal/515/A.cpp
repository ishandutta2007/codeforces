#include <bits/stdc++.h>
using namespace std;

long long a, b, s;

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%I64d %I64d %I64d", &a, &b, &s);
    if ((a + b - s) & 1 || s < abs(a) + abs(b)) puts("No");
    else puts("Yes");

    return 0;
}