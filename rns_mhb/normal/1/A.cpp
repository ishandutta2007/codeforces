#include <bits/stdc++.h>
using namespace std;

int n, m, a;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("11.in", "w", stdout);
    #endif
    
    scanf("%d %d %d", &n, &m, &a);
    printf("%I64d", 1ll * ((n - 1) / a + 1) * ((m - 1) / a + 1));

    return 0;
}