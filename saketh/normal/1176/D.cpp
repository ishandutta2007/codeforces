#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const int MAXV = 2'750'131 + 5;
    vi sieve(MAXV, -1);
    vi primes = { 0 };

    for (int p = 2; p < MAXV; p++) if (sieve[p] == -1) {
        primes.push_back(p);
        for (int q = p; q < MAXV; q += p)
            if (sieve[q] == -1) sieve[q] = p;
    }

    assert(primes[199999] == 2750131);

    int N;
    cin >> N;

    map<int, int> apps;
    vi comp;
    for (int i = 0, v; i < 2 * N; i++) {
        cin >> v;
        apps[v]++;

        if (sieve[v] != v)
            comp.push_back(v);
    }

    vi res;

    sort(all(comp), greater<int>());
    for (int v : comp) {
        for (int c = 0; c < apps[v]; c++)
            res.push_back(v);
        apps[v / sieve[v]] -= apps[v];
        apps[v] = 0;
    }

    vi remain;
    for (auto [k, v] : apps) {
        remain.push_back(k);
    }
    sort(all(remain));

    for (int v : remain) if (apps[v]) {
        for (int c = 0; c < apps[v]; c++) {
            res.push_back(v);
        }
        apps[primes[v]] -= apps[v];
        apps[v] = 0;
    }

    for (int v : res)
        cout << v << " ";
    cout << endl;

    return 0;
}