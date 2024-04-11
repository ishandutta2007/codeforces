#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MAXN = (int) 3e5 + 5;

int n;
LL a[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
    }
    
    LL ans = 0;
    LL small = 0;
    for (int i = 1; i <= n; ++i) {
        LL t = min(small, a[i] / 2);
        
        small -= t;
        a[i] -= t * 2;
        ans += t;
        
        t = a[i] / 3;
        a[i] -= t * 3;
        ans += t;
        
        small += a[i];
    }
    
    printf("%lld\n", ans);
    
    return 0;
}