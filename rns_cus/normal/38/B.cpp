#include <bits/stdc++.h>
using namespace std;

#define N 11

char rk[N], kn[N];

int main() {
    scanf("%s %s", rk, kn);
    int ans = 0;
    for (char a = 'a'; a <= 'h'; a ++) {
        for (char b = '1'; b <= '8'; b ++) {
            if (a == rk[0] || b == rk[1]) continue;
            if (a == kn[0] && b == kn[1]) continue;
            if (abs((a - kn[0]) * (b - kn[1])) == 2) continue;
            if (abs((a - rk[0]) * (b - rk[1])) == 2) continue;
            ans ++;
        }
    }
    printf("%d\n", ans);

    return 0;
}