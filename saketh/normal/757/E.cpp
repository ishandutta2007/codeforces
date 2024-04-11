#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int MOD = 1e9 + 7;
int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

const int MAXV = 1e6 + 100;
vi fact(MAXV);
vi finv(MAXV);

int mod_pow(int b, int e) {
    if (e == 0) return 1;
    if (e & 1) return prod(mod_pow(b, e-1), b);
    return mod_pow(prod(b, b), e/2);
}

int ncr(int n, int r) {
    if (n < 0 || r < 0 || n - r < 0) return 0;
    int ret = prod(fact[n], prod(finv[r], finv[n-r]));
    return ret;
}

int solve(int N, int J) {
    int res = sum(prod(2, ncr(N-1, J-1)), ncr(N-1, J));
    return res;
}

int main() {
    fact[0] = 1;
    finv[0] = 1;
    for (int i = 1; i < MAXV; i++) {
        fact[i] = prod(i, fact[i-1]);
        finv[i] = mod_pow(fact[i], MOD-2);
    }

    vi sieve(MAXV);
    for (int p = 2; p < MAXV; p++) {
        if (sieve[p]) continue;
        for (int q = p; q < MAXV; q += p)
            sieve[q] = p;
    }

    int Q;
    scanf("%d", &Q);
    for (int q = 0; q < Q; q++) {
        int R, N;
        scanf("%d %d", &R, &N);

        int ans = 1;

        while (N > 1) {
            int p = sieve[N];
            int ct = 0;
            while (N % p == 0) {
                ct++;
                N /= p;
            }
            ans = prod(ans, solve(R + ct, ct));
        }

        printf("%d\n", ans);
    }

    return 0;
}