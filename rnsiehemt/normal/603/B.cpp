#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 1000005;
const ll Mod = 1000*1000*1000+7;

int P, K;
bool seen[MaxN];
ll ans = 1, other = 1;

int main()
{
    scanf("%d%d", &P, &K);
    if (K == 0) {
        for (int i = 1; i < P; i++) ans = (ans * P) % Mod;
    } else {
        for (int i = 1; i < P; i++) if (!seen[i]) {
            for (int j = (ll(K)*i)%P; !seen[j]; j = (ll(K)*j)%P) {
                seen[j] = true;
            }
            ans = (ans * P) % Mod;
        }
    }
    for (int i = 1; i < P; i++) if ((ll(K)*i)%P == i) other++;
    ans = (ans * other) % Mod;
    printf("%lld\n", ans);
}