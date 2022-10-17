#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const int MAXV = 1e5 + 1;
    vi sieve(MAXV);
    vi primes;
    for (int p = 2; p < MAXV; p++) {
        if (sieve[p]) continue;
        primes.push_back(p);
        for (int q = p; q < MAXV; q += p)
            sieve[q] = p;
    }

    ll N;
    cin >> N;

    int inx = -1;
    for (int i = 0; i < primes.size(); i++) {
        if (N % primes[i] == 0) {
            inx = i;
            break;
        }
    }

    if (inx == -1) {
        cout << 1 << endl;
        return 0;
    }

    ll steps = 0;
    while (N > 0) {
        ll stop = 0;
        int ninx = -1;
        for (int j = 0; j < inx; j++) {
            ll prod = primes[j] * 1ll * primes[inx];
            ll meet = (N - 1) / prod * prod;
            if (meet > stop) {
                stop = meet;
                ninx = j;
            }
        }

        steps += (N - stop) / primes[inx];
        N = stop;
        inx = ninx;
    }

    cout << steps << endl;
    return 0;
}