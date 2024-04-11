#include <bits/stdc++.h>
using namespace std;

#define N 1000000

int k, q, f[6];
typedef long long ll;
ll dp[N];
const ll inf = -1e18;

typedef pair <ll, int> pli;

int main() {
    scanf("%d", &k);
    for (int i = 0; i < 6; i ++) scanf("%d", &f[i]);
    for (int i = 1; i < N; i ++) dp[i] = inf;
    dp[0] = 0;
    for (int i = 0, w = 3; i < 6; i ++, w *= 10) {
        int c = f[i], up = 3 * (k - 1);
        for (int r = 0; r < w; r ++) {
            deque <pli> dq;
            for (int j = r, p = 0; j < N; j += w, p ++) {
                ll val = dp[j] - 1ll * c * p;
                if (!dq.empty() && dq.back().first < val) dq.pop_back();
                dq.push_back(pli(val, p));
                if (dq.front().second == p - up - 1) dq.pop_front();
                dp[j] = dq.front().first + 1ll * c * p;
            }
        }
    }

    for (int d = 0, pw = 1; d < 6; d ++, pw *= 10) {
        for (int i = N - 1; i >= 0; i --) {
            for (int j = 1; j <= 9; j ++) {
                long long c = 0, a = j * pw;
                if (i + a >= N) continue;
                if (j % 3 == 0) c = 1ll * j / 3 * f[d];
                dp[i+a] = max(dp[i+a], dp[i] + c);
            }
        }
    }

    int q;
    scanf("%d", &q);
    while (q --) {
        int n;
        scanf("%d", &n);
        printf("%I64d\n", dp[n]);
    }

}