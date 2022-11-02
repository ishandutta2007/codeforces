#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 1000005;
const ll Mod = 1000*1000*1000+7;

int N, a[MaxN], idx[MaxN];
ll L, K, ans;
std::vector<ll> dp[MaxN];

bool cmp(const int &i, const int &j) {
    return a[i] < a[j];
}
void fix(ll &a) {
    if (a >= Mod) a -= Mod;
    else if (a < 0) a += Mod;
}

int main()
{
    scanf("%d%lld%lld", &N, &L, &K);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    
    for (int i = 0; i < N; i++) idx[i] = i;
    std::sort(idx, idx+N, cmp);
    
    for (int k = 0; k < K; k++) dp[k].resize(N);
    for (int i = 0; i < N; i++) {
        dp[0][i] = 1;
    }
    for (int k = 0; k+1 < K; k++) {
        int s = 0, e = 0;
        ll cur = 0;
        while (s < N) {
            while (e < N && a[idx[e]] == a[idx[s]]) e++;
            for (int i = s; i < e; i++) {
                cur += dp[k][idx[i]];
                fix(cur);
            }
            for (int i = s; i < e; i++) {
                dp[k+1][idx[i]] += cur;
                fix(dp[k+1][idx[i]]);
            }
            s = e;
        }
    }
    for (int k = 0; k < K; k++) for (int i = 0; i < N; i++) {
        ll p = ll(k) * N + i;
        if (p < L) {
            ll times = (((L+N-1) - p) / N) % Mod;
            //printf("%d %d %d %lld %lld\n", k, i, k*N+i, dp[k][i], times);
            ans += dp[k][i] * times;
            ans %= Mod;
        }
    }
    printf("%lld\n", ans);
}