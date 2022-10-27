#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 200+10;
int t, n, k;
int x[N];

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= k; i ++)
            scanf("%d", &x[i]);

        for (int i = 1; i <= 200; i ++) {
            bool fg = 1;
            for (int j = 1; j <= n; j ++) {
                bool fg_ = 0;
                for (int q = 1; q <= k; q ++) {
                    if ( abs(x[q] - j) < i ) fg_ = 1;
                }
                fg &= fg_;
            }
            if (fg) {
                printf("%d\n", i);
                break;
            }
        }
    }
}