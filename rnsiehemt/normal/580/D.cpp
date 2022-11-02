#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define push_back pb
#define emplace_back eb
#define mod(x) ((x)%Mod)
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 18;
const ll inf = 1e17;

int N, M, K, bitcount[1 << MaxN];
ll a[MaxN], e[MaxN][MaxN], dp[1 << MaxN][MaxN], ans;

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < N; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < K; i++) {
        int x, y; scanf("%d%d", &x, &y); x--; y--;
        scanf("%lld", &e[x][y]);
    }

    for (int i = 0; i < (1 << N); i++) std::fill(dp[i], dp[i]+N, -inf);
    for (int i = 0; i < N; i++) dp[1 << i][i] = a[i];
    for (int i = 1; i < (1 << N); i++) {
        bitcount[i] = bitcount[i - (i&-i)] + 1;
        for (int k = 0; k < N; k++) if (dp[i][k] > -inf) {
            for (int j = 0; j < N; j++) if (!(i & (1 << j))) {
                domax(dp[i | (1 << j)][j], dp[i][k] + a[j] + e[j][k]);
            }
            if (bitcount[i] == M) domax(ans, dp[i][k]);
        }
    }

    printf("%lld\n", ans);
}