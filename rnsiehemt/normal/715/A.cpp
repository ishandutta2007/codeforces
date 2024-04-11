#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 100*1000+5;

ll n;

int main() {
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        if (i > 1) printf("%lld\n", i*(i+1)*(i+1) - (i-1));
        else printf("%lld\n", 2ll);
    }
}