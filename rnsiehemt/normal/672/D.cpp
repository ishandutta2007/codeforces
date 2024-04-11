#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 500*1000+5;

int n;
ll k, c[maxn], s[maxn];

ll timered(ll d) {
    int i = std::lower_bound(c, c+n, d) - c;
    return s[n] - s[i] - (n-i) * d;
}
ll timeadd(ll d) {
    int i = std::upper_bound(c, c+n, d) - c;
    return i * d - s[i];
}

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) scanf("%lld", c+i);
    std::sort(c, c+n);
    for (int i = 0; i < n; i++) s[i+1] = s[i] + c[i];
    ll lo = 0, hi = 1e9+2;
    while (lo < hi) {
        ll mid = (lo+hi)/2;
        if (timered(mid) <= k) hi = mid;
        else lo = mid+1;
    }
    ll red = lo;
    //printf("%lld\n", red);
    lo = 0; hi = 1e9+2;
    while (hi-lo > 1) {
        ll mid = (lo+hi)/2;
        if (timeadd(mid) <= k) lo = mid;
        else hi = mid;
    }
    ll add = lo;
    //printf("%lld\n", add);
    if (add >= red) {
        if (s[n] % ll(n) == 0) printf("0\n");
        else printf("1\n");
    } else {
        printf("%lld\n", red - add);
    }
}