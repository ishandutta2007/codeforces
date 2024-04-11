#include<bits/stdc++.h>
using namespace std;

int main() {
    long long yy, bb, y, g, b, yyy, bbb;
    scanf("%I64d%I64d%I64d%I64d%I64d", &yy, &bb, &y, &g, &b);
    yyy = 2 * y + g;
    bbb = 3 * b + g;
    long long rlt;
    rlt = max(0ll, yyy - yy) + max(0ll, bbb - bb);
    printf("%I64d\n", rlt);
}