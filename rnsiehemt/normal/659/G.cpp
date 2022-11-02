#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define mod(x) ((x)%Mod)
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 1000*1000+5;
const ll Mod = 1000*1000*1000+7;

int n;
ll h[maxn], dp[maxn], ans;

void add(ll &a, ll b) {
    a += b;
    if (a >= Mod) a -= Mod;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", h+i);
    h[n] = 1;
    add(ans, h[0]-1);
    add(dp[1], std::min(h[0], h[1])-1);
    for (int i = 1; i < n; i++) {
        ll prevh = 1;
        ll curh = std::min(std::min(h[i-1], h[i]), h[i+1]);
        add(ans, mod((curh-prevh) * (dp[i] + 1)));
        add(dp[i+1], mod((curh-prevh) * (dp[i] + 1)));
        
        prevh = curh;
        if (h[i-1] > h[i+1]) {
            curh = std::min(h[i-1], h[i]);
            add(ans, mod((curh-prevh) * (dp[i] + 1)));
        } else {
            curh = std::min(h[i], h[i+1]);
            add(ans, curh-prevh);
            add(dp[i+1], curh-prevh);
        }
        
        add(ans, h[i]-curh);
    }
    printf("%lld\n", ans);
}