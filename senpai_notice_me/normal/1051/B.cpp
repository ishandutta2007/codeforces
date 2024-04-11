#include <bits/stdc++.h>

using namespace std;

using LL = long long;

int main() {
    LL l, r;
    
    scanf("%I64d%I64d", &l, &r);
    
    puts("YES");
    for (LL i = l; i <= r; i += 2)
        printf("%I64d %I64d\n", i, i + 1);
    
    return 0;
}