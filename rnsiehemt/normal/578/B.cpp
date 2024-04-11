#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define pb push_back
#define eb emplace_back
#define mod(x) ((x)%Mod)
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 200005;

int N, K;
ll X, a[MaxN], lor[MaxN], ror[MaxN], ans;

int main()
{
    scanf("%d%d%lld", &N, &K, &X);
    for (int i = 0; i < N; i++) scanf("%lld", &a[i]);

    for (int i = 1; i < N; i++) lor[i] = lor[i-1] | a[i-1];
    for (int i = N-1; i >= 0; i--) ror[i] = ror[i+1] | a[i+1];
    for (int i = 0; i < N; i++) {
        ll foo = a[i];
        for (int k = 0; k < K; k++) foo *= X;
        domax(ans, lor[i] | ror[i] | foo);
    }
    printf("%lld\n", ans);
}