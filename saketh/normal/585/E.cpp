#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXV = 1e7 + 500;
const int MAXN = 5e5 + 500;

const int MOD = 1e9 + 7;
int neg(int a) { return a == 0 ? 0 : MOD - a; }
int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

int mu[MAXV];
int sieve[MAXV];
int p2m1[MAXV];

void init() {
    for (int p = 2; p < MAXV; p++) {
        if (sieve[p]) continue;
        for (int q = p; q < MAXV; q += p)
            sieve[q] = p;
    }

    mu[1] = 1;
    for (int p = 2; p < MAXV; p++) {
        int l = sieve[p];
        if ((p / l) % l == 0) mu[p] = 0;
        else mu[p] = -1 * mu[p / l];
    }

    for (int i = 1; i < MAXV; i++)
        p2m1[i] = sum(prod(p2m1[i-1], 2), 1);
}

int contr(int coeff, int apps) {
    if (coeff == 0) return 0;
    if (coeff == -1) return neg(p2m1[apps]);
    return p2m1[apps];
}

int N;
int val[MAXN];

int ct[MAXV];
vector<int> divs;

void put(int i, bool c) {
    divs.clear();
    int v = val[i];

    vector<int> primes;
    for (int t = v; t > 1; ) {
        int p = sieve[t];
        primes.push_back(p);
        while (t % p == 0) t /= p;
    }

    int P = primes.size();
    for (int m = 0; m < (1<<P); m++) {
        int prod = 1;
        for (int i = 0; i < P; i++)
            if ((m>>i)&1)
                prod *= primes[i];

        divs.push_back(prod);
        if (c) ct[prod]++;
    }
}

int main() {
    init();

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", val + i);
        put(i, true);
    }

    int g1 = 0;
    for (int v = 1; v < MAXV; v++) {
        g1 = sum(g1, contr(mu[v], ct[v]));
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int gw = g1;        

        put(i, false);
        for (int d : divs) {
            gw = sum(gw, neg(contr(mu[d], ct[d])));
            gw = sum(gw, contr(mu[d], ct[d] - 1));
        }

        ans = sum(ans, sum(g1, neg(prod(gw, 2))));
    }

    printf("%d\n", ans);
}