#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 400000+10;
int Q, op; 
LL p, q, R, W, a[N], last, c = 1;
LL nex[N][30], sum[N][30];
LL find(int x) {
    if (a[x] >= W || x == 0) return x;
    return find(nex[x][0]);
}
int main() {
    scanf("%d", &Q); 
    memset(sum, -1, sizeof sum);
    sum[1][0] = nex[1][0] = 0, a[0] = 0;
    while (Q --) {
        scanf("%d %lld %lld", &op, &p, &q);
        R = p ^ last, W = q ^ last;
        if (op == 1) {
            ++ c, a[c] = W;
            nex[c][0] = find(R); sum[c][0] = W;
            for (int bit = 1; bit < 20; bit ++) {
                nex[c][bit] = nex[ nex[c][bit-1] ][bit-1];
                if (sum[c][bit-1] != -1 && sum[ nex[c][bit-1] ][bit-1] != -1)
                    sum[c][bit] = sum[c][bit-1] + sum[ nex[c][bit-1] ][bit-1];
            }
        }
        if (op == 2) {
            LL ans = 0;
            for (int i = 20; i >= 0; i --) {
                if (W >= sum[R][i] && sum[R][i] != -1) {
                    W -= sum[R][i], ans += (1 << i); R = nex[R][i];
                }
            }
            printf("%lld\n", ans);
            last = ans;
        }
    }
}