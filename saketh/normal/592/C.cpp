#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// check if X * Y / G is over L
bool big(ll X, ll Y, ll G, ll L) {
    ll A = X / G;
    ll B = Y;

    if (A <= L / B) return false;
    return true;
}

void print_frac(ll N, ll D) {
    ll G = gcd(N, D);
    cout << N / G << "/" << D / G << "\n";
}

int main() {
    ll T, W, B;
    cin >> T >> W >> B;

    // special case if the LCM of W and B is bigger than T
    if (big(W, B, gcd(W, B), T)) {
        print_frac(min(min(W, B) - 1, T), T);
    } else {
        ll LCM = W / gcd(W, B) * B;
            
        ll OK = min(W, B);
        ll ans = OK * (T / LCM);

        if (T % LCM) {
            ans += min(OK - 1, T % LCM);
        }

        print_frac(ans, T);
    }
}