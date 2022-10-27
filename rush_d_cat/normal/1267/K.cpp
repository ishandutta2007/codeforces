#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL fac[30];

int main() {
    fac[0] = 1;
    for (int i = 1; i < 30; i ++) fac[i] = fac[i-1] * i;

    // printf("%.5f\n", 9600/128.0);
    int t; scanf("%d", &t);
    while (t --) {
        LL x;
        scanf("%lld", &x);
        vector<int> v;
        for (int i = 2;; i ++) {
            // printf("! %d\n", x % i);
            v.push_back(x % i); x /= i;
            if (x == 0) break;
        }
        int c[30] = {0};
        for (auto x: v) c[x] ++;
        LL ans = 0;

        int ways = c[0];

        for (int j = 1; j < 20; j ++) {
            if (c[j] == 0) continue;
            LL tmp = c[j];
            c[j] --;
            ways = c[0];
            for (int i = 1; i < v.size(); i ++) {
                ways += c[i];
                tmp = tmp * (ways - (i-1));
            }
            c[j] ++;
            ans = ans + tmp;
        }
        for (int i = 0; i < 20; i ++) {
            ans =  ans / fac[c[i]];
        }
        printf("%lld\n", ans - 1);
    }
}