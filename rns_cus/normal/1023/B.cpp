#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    scanf("%I64d %I64d", &n, &k);
    long long rlt = max(0ll, min(n, k - 1) - max((k + 1) / 2, k - n) + 1);
    if (k % 2 == 0 && k / 2 <= n) rlt --;
    printf("%I64d\n", rlt);

    return 0;
}