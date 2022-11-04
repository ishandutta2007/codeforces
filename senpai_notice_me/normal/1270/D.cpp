#include <bits/stdc++.h>

using namespace std;

map<int, int> cnt;

int main() {
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= k + 1; ++i) {
        printf("?");
        for (int j = 1; j <= k + 1; ++j) if (j != i) {
            printf(" %d", j);
        }
        putchar('\n');
        fflush(stdout);
        
        int x, y;
        scanf("%d%d", &x, &y);
        
        cnt[y] += 1;
    }
    
    printf("! %d\n", (--cnt.end())->second);
    
    return 0;
}