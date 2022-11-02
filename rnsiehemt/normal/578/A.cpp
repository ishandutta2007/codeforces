#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define pb push_back
#define eb emplace_back
#define mod(x) ((x)%Mod)
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

ll a, b;

int main()
{
    scanf("%lld%lld", &a, &b);
    if (b > a) printf("-1\n");
    else {
        ll lo = 1, hi = 1000*1000*1000+5;
        while (hi - lo > 1) {
            ll mid = (lo+hi)/2;
            if (a-b >= 2*mid*b) lo = mid;
            else hi = mid;
        }
        //printf("%lld\n", lo);
        double ans = 1e9;
        if (a-b >= 2*lo*b) domin(ans, double(a-b) / (2*lo));

        lo = 1, hi = 1000*1000*1000+5;
        while (hi - lo > 1) {
            ll mid = (lo+hi)/2;
            if (a+b >= 2*mid*b) lo = mid;
            else hi = mid;
        }
        //printf("%lld\n", lo);
        domin(ans, double(a+b) / (2*lo));
        
        printf("%.10lf\n", ans);
    }
}