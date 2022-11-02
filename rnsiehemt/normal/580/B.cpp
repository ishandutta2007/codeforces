#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define push_back pb
#define emplace_back eb
#define mod(x) ((x)%Mod)
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005;

int N, D;
std::pair<int, int> f[MaxN];
ll ans = 0;

int main()
{
    scanf("%d%d", &N, &D);
    for (int i = 0; i < N; i++) scanf("%d%d", &f[i].first, &f[i].second);

    std::sort(f, f+N);
    int e = 0; ll cur = 0;
    for (int s = 0; s < N; s++) {
        while (e < N && f[e].first - f[s].first < D) {
            cur += f[e].second;
            e++;
        }
        domax(ans, cur);
        cur -= f[s].second;
    }

    printf("%lld\n", ans);
}