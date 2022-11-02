#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 100*1000+5;

int n;
ll k, a[maxn], b[maxn];

bool f(ll t) {
    ll x = k;
    for (int i = 0; i < n; i++) {
        x -= std::max(a[i]*t - b[i], 0ll);
        if (x < 0) return false;
    }
    return true;
}

int main() {
    scanf("%d%lld", &n, &k);
    //for (int i = 0; i < n; i++) scanf("%lld%lld", a+i, b+i);
    for (int i = 0; i < n; i++) scanf("%lld", a+i);
    for (int i = 0; i < n; i++) scanf("%lld", b+i);
    f(1);
    ll lo = 0, hi = 2e9+5;
    while (hi-lo > 1) {
        ll mid = (lo+hi)/2;
        if (f(mid)) lo = mid;
        else hi = mid;
    }
    printf("%lld\n", lo);
}