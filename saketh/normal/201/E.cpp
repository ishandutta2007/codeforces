#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// find A * B / C, where if the result is above N just give back N
ll safe_mult(ll A, ll B, ll C, ll N) {
    if( (C * N + (B - 1)) / B <= A) return N;
    return A * B / C;
}

bool can_do(ll N, ll M, ll K) {
    ll strings = N;
    ll slots = K * M;

    ll ways = 1;
    for (ll bits = 0; bits <= K; bits++) {
        ll take = bits ? slots / bits : 1;
        take = min(take, ways);
        
        strings = max(0ll, strings - take);
        if(!strings) break;
        if(!take) break;

        slots -= take * bits;
        if(!slots) break;

        if(bits < K)
        ways = safe_mult(ways, K - bits, bits + 1, strings);
    }

    return strings == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int T;

    for (cin >> T; T; T--) {
        ll N, M;
        cin >> N >> M;

        ll ans = 1e9, lo = 0, hi = 1e9;

        while(lo <= hi) {
            ll mi = (lo + hi) / 2;

            if(can_do(N, M, mi)) {
                ans = mi;
                hi = mi - 1;
            }
            else lo = mi + 1;
        }

        cout << ans << "\n";
    }
}