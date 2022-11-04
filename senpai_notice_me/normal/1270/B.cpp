#include <bits/stdc++.h>

using namespace std;

int main() {
    int case_cnt; scanf("%d", &case_cnt);
    while (case_cnt--) {
        int n; scanf("%d", &n);
        bool ans = false;
        int pos = 0;
        
        int x, y;
        scanf("%d", &x);
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &y);
            if (abs(x - y) > 1) {
                pos = i - 1;
                ans = true;
            }
            x = y;
        }
        
        if (ans) {
            puts("YES");
            printf("%d %d\n", pos, pos + 1);
        } else {
            puts("NO");
        }
    }
    
    return 0;
}