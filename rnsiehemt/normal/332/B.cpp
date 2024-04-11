// change %I64d to %lld to compile

#include <cstdio>
#include <algorithm>

typedef long long ll;

int N, K;
ll a[200010]; // absurdity
ll s[200010]; // sum [i, i+K)
ll m[200010]; // max of s[i], ..., s[N-K]
ll midx[200010]; // index j of said maximum

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%I64d", &a[i]);

    ll t = 0; for (int i = 0; i < K; i++) t += a[i];
    for (int i = 0; i+K <= N; i++) {
        s[i] = t;
        t = t + a[i+K] - a[i];
    }

    for (int i = N-K; i >= 0; i--) {
        if (m[i+1] > s[i]) {
            m[i] = m[i+1];
            midx[i] = midx[i+1];
        }
        else {
            m[i] = s[i];
            midx[i] = i;
        }
    }

    ll best = 0ll;
    int besta, bestb;
    for (int i = 0; i+K+K <= N; i++) {
        if (s[i] + m[i+K] > best) {
            best = s[i] + m[i+K];
            besta = i;
            bestb = midx[i+K];
        }
    }

    printf("%d %d\n", besta+1, bestb+1);
}