#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

ll modexp(ll b, ll e) {
    if (e == 0) return 1;
    else return (e & 1 ? b : 1) * modexp(b * b % MOD, e / 2) % MOD;
}

int main() {
    ll n, m, k, r, c; cin >> n >> m >> k >> r >> c;
    ll ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
    ll freeCount;
    if (ax == bx && ay == by) {
        freeCount = n * m;
    } else { 
        freeCount = n * m - r * c;
    }
    printf("%lld\n", modexp(k, freeCount));
}