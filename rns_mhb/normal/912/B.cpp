#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;

int main() { 
    scanf("%I64d %I64d", &n, &k);
    if (k == 1) return printf("%I64d\n", n), 0;
    ll nn = 1;
    while (nn < n) nn = nn << 1 | 1;
    printf("%I64d\n", nn);
    return 0;
}