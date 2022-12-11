#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MD = 998244353;

struct init_t {
    vector<ll> fac;
    vector<ll> ofac;
    explicit init_t(int N = 3e5) {
        fac.assign(N, 1);
        for (int i = 1; i < N; i++) {
            fac[i] = fac[i - 1] * i % MD;
        }
        ofac.assign(N, my_pow(fac.back(), MD - 2));
        for (int i = N - 2; i >= 0; i--) {
            ofac[i] = ofac[i + 1] * (i + 1) % MD;
        }
    }

private:
    ll my_pow(ll a, ll pow) {
        if (pow == 0) return 1;
        if (pow % 2) return a * my_pow(a, pow - 1) % MD;
        ll q = my_pow(a, pow / 2);
        return q * q % MD;
    }
};

ll solve(ll a, const init_t &data, const vector<ll> &primes) {
    ll ans = 1;
    int num_primes = 0;
    for (int i = 0; primes[i] * primes[i] <= a; i++) {
        if (a % primes[i]) continue;
        int deg = 0;
        while (a % primes[i] == 0) {
            deg++;
            a /= primes[i];
        }
        ans = (ans * data.ofac[deg]) % MD;
        num_primes += deg;
    }
    if (a > 1) {
        num_primes++;
    }
    return data.fac[num_primes] * ans % MD;
}

void solve(const init_t &data) {
    ll x;
    cin >> x;
    vector<ll> primes;
    for (ll d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            for (primes.push_back(d); x % d == 0; x /= d);
        }
    }
    if (x > 1) {
        primes.push_back(x);
    }
    primes.push_back(MD);

    int q;
    cin >> q;
    while (q --> 0) {
        ll a, b;
        cin >> a >> b;
        ll g = __gcd(a, b);
        cout << solve(a / g, data, primes) * solve(b / g, data, primes) % MD << "\n";
    }
}

int main() {
    init_t data;
    solve(data);
}