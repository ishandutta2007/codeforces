#include <bits/stdc++.h>
using namespace std;

#define N 100005

typedef long long ll;
ll n;
int q;
char s[N];

int main() {
    scanf("%I64d %d", &n, &q);
    while (q --) {
        ll x;
        scanf("%I64d ", &x);
        gets(s);
        for (int i = 0; s[i]; i ++) {
            ll y = x, ox = x;
            int al = 0;
            while (y % 2 == 0) y >>= 1, al ++;
            if (s[i] == 'U') {
                if (x == n + 1 >> 1) continue;
                if (y % 4 == 1) x = (1ll << al + 1) * (y >> 1 | 1);
                else x = (1ll << al + 1) * (y >> 1);
            }
            else {
                if (!al) continue;
                if (s[i] == 'L') x = (1ll << al - 1) * ((y << 1) - 1);
                else x = (1ll << al - 1) * ((y << 1) + 1);
            }
        }
        printf("%I64d\n", x);
    }
    return 0;
}