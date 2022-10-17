#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXV = 1e5 + 500;

int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

int sieve[MAXV];
int fact[MAXV];
int mu[MAXV];

void init() {
    for (int p = 2; p < MAXV; p++) {
        if (sieve[p]) continue;
        for (int q = p; q < MAXV; q += p) 
            sieve[q] = p;
    }

    mu[1] = 1;
    for (int v = 2; v < MAXV; v++) {
        int p = sieve[v];
        if ((v / p) % p == 0) mu[v] = 0;
        else mu[v] = -mu[v/p];
    }

    fact[0] = 1;
    for (int v = 1; v < MAXV; v++)
        fact[v] = prod(v, fact[v-1]);
}

int mod_pow(int b, int e) {
    if (e == 0) return 1;
    if (e & 1) return prod(b, mod_pow(b, e-1));
    return mod_pow(prod(b, b), e / 2);
}

int inv(int v) {
    return mod_pow(v, MOD - 2);
}

int ncr(int n, int r) {
    if (r > n || r < 0) return 0;
    return prod(fact[n], inv(prod(fact[r], fact[n-r])));
}

int solve(int F, int N) {
    vector<int> primes;

    for (int T = F; T > 1;) {
        int P = sieve[T];
        primes.push_back(P);
        while (T % P == 0) T /= P;
    }

    int res = 0;
    for (int m = 0; m < (1 << primes.size()); m++) {
        int v = 1;
        for (int i = 0; i < primes.size(); i++)
            if ((m >> i)&1)
                v *= primes[i];

        int S = F / v;
        S -= N;
        int ways = ncr(S + N - 1, S);
        res = sum(res, prod(ways, (MOD + mu[v]) % MOD));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);
    
    init();

    int Q, F, N;

    for (cin >> Q; Q; Q--) {
        cin >> F >> N;
        cout << solve(F, N) << "\n";
    }
}