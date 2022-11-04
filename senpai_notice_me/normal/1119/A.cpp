#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 3e5 + 5;

int n, c[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", c + i);
    }
    
    int sec = 0;
    for (int i = 2; i <= n; ++i) if (c[i] != c[1]) {
        sec = i; break;
    }
    
    int ans = sec - 1;
    for (int i = sec + 1; i <= n; ++i) {
        if (c[i] != c[1]) ans = max(ans, i - 1);
        if (c[i] != c[sec]) ans = max(ans, i - sec);
    }
    
    cout << ans << endl;
    
    return 0;
}