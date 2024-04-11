#include <bits/stdc++.h>

int main() {
    int ans = 0;
    
    int n; scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        static int x, y;
        
        scanf("%d%d", &x, &y);
        
        ans = std::max(ans, x + y);
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}