#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool look(T &a, T b = true) { return (a == b ? true : (a = b, false)); }
typedef long long ll;

ll x;
std::vector<ll> y, z;

int main()
{
    scanf("%lld", &x);
    ll a = 1, b = x, cur = x;
    y.push_back(a); z.push_back(b);
    while (a < 1500*1000 && b > a) {
        cur += (b*(b+1) - (b-a-1)*(b-a)) / 2;
        a++;
        //printf("%lld\n", cur);
        
        ll k = b-a;
        if (cur - k*(a*a + a)/2 > x) break;
        ll lo = 0, hi = b-a+1;
        while (lo+1 < hi) {
            ll mid = (lo+hi)/2;
            if (cur - mid*(a*a + a)/2 >= x) lo = mid;
            else hi = mid;
        }
        //printf("%lld\n", lo);
        b -= lo;
        cur -= lo*(a*a + a)/2;
        if (cur == x) {
            y.push_back(a); z.push_back(b);
        }
    }
    int ans = sz(y)*2;
    if (y.back() == z.back()) ans--;
    printf("%d\n", ans);
    for (int i = 0; i < sz(y); i++) printf("%lld %lld\n", y[i], z[i]);
    for (int i = sz(y)-1; i >= 0; i--) if (z[i] != y[i]) printf("%lld %lld\n", z[i], y[i]);
}