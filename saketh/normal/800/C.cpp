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

const int MAXM = 2e5 + 100;
int sieve[MAXM], phi[MAXM];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int mpow(int b, int e, int M) {
    if (e == 0) return 1;
    if (e & 1) return mpow(b, e - 1, M) * 1ll * b % M;
    return mpow(b * 1ll * b % M, e / 2, M);
}

int find(int X, int Y, int M) {
    int g1 = gcd(X, M);
    int g2 = gcd(Y, M);

    if (g2 % g1 != 0) assert(0);

    int res = 1ll * (g2 / g1) * (Y / g2) * mpow(X / g1, phi[M] - 1, M) % M;

    assert(X * 1ll * res % M == Y);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    for (int p = 2; p < MAXM; p++) {
        if (sieve[p]) continue;
        for (int q = p; q < MAXM; q += p)
            sieve[q] = p;
    }

    phi[1] = 1;
    for (int p = 2; p < MAXM; p++) {
        int s = p / sieve[p];

        if (sieve[s] == sieve[p])
            phi[p] = phi[s] * sieve[p];
        else phi[p] = phi[s] * (sieve[p] - 1);
    }

    /*srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        int M = (rand() % 200000) + 1;
        int X = (rand() % M), Y = (rand() % M);
        cout << "Test " << X << " " << Y << " mod " << M << ": ";
        cout << find(X, Y, M) << endl;
    }*/

    int N, M;
    cin >> N >> M;

    vector<bool> ban(M);
    for (int i = 0; i < N; i++) {
        int V;
        cin >> V;
        ban[V] = true;
    }

    vvi elts(M + 1);
    for (int i = 0; i < M; i++) {
        if (!ban[i])
            elts[gcd(i, M)].push_back(i);
    }

    vi primes;
    for (int tmp = M; tmp > 1; tmp /= sieve[tmp])
        primes.push_back(sieve[tmp]);

    int ans = 0;
    vi best;

    sort(all(primes));
    do {
        int score = 0, allow = 1;
        for (int i = 0; i <= primes.size(); i++) {
            score += elts[allow].size();
            if (i < primes.size()) allow *= primes[i];
        }
        if (score > ans) {
            ans = score;
            best = primes;
        }
    } while (next_permutation(all(primes)));

    int allow = 1;
    int prod = 1;

    vi res;

    for (int i = 0; i <= best.size(); i++) {
        for (int v : elts[allow]) {
            res.push_back(find(prod, v, M));
            prod = v;
        }
        if (i < primes.size()) allow *= best[i];
    }

    /* VERIFICATION */
    /*vb seen(M);
    prod = 1;
    for (int v : res) {
        prod = prod * 1ll * v % M;

        assert(v >= 0 && v < M);
        assert(!seen[prod]);
        assert(!ban[prod]);

        seen[prod] = true;
    }*/
    /* END VERIFICATION */

    cout << ans << endl;
    for (int v : res) cout << v << " ";
    cout << endl;

    return 0;
}