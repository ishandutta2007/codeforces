#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int x;
char s[N];
const int mod = 1e9 + 7;

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %s", &x, s + 1);
        int k = 1, len = strlen(s + 1);
        bool ed = 0;
        for (k = 1; k <= x; k ++) {
            int c = s[k] - '0' - 1, l = len;
            int nxtl = (len + 1ll * c * (len - k + mod)) % mod;
            while (c --) {
                if (len == x) ed = 1;
                if (ed) break;
                for (int j = k + 1; j <= l && len < x; j ++) {
                    s[++len] = s[j];
                }
                if (len == x) ed = 1;
            }
            len = nxtl;
        }
        printf("%d\n", len);
    }

    return 0;
}