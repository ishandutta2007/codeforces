#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
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

const ll MOD = 1ll << 32;
ll sum(ll a, ll b) { return (a + b) % MOD; }
ll prod(ll a, ll b) { return a * 1ll * b % MOD; }

void proc(ll &ans, int p, ll N, ll A, ll B, ll C, ll D) {
    ll f = sum(D, prod(p, sum(C, prod(p, sum(B, prod(p, A))))));
    for (ll v = p; v <= N; v *= p) {
        ans = sum(ans, prod(f, N/v));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const int SEG = 20000;

    bitset<SEG> sieve;
    vi primes;

    for (int p = 2; p < SEG; p++) {
        if (sieve[p]) continue;
        primes.push_back(p);
        for (int q = p * p; q < SEG; q += p)
            sieve[q] = true;
    }

    int ct = primes.size();

    ll N, A, B, C, D, ans = 0;
    cin >> N >> A >> B >> C >> D;

    for (int p : primes) {
        proc(ans, p, N, A, B, C, D);
    }

    const int MAXN = 3e8;
    for (int v = SEG; v <= MAXN; v += SEG) {
        for (int i = 0; i < SEG; i++)
            sieve[i] = true;

        for (int p : primes) {
            int q = v - (v % p);
            if (q < v) q += p;
            for(; q < v + SEG; q += p)
                sieve[q - v] = false;
        }

        for (int i = 0; i < SEG; i++)
            if (sieve[i])
                proc(ans, v + i, N, A, B, C, D);
    }


    cout << ans << endl;
    return 0;
}