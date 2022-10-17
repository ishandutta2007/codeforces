#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const int MAXV = 1e6 + 100;

    vector<int> sieve(MAXV);

    for (int p = 2; p < MAXV; p++) {
        if (sieve[p]) continue;
        for (int q = p; q < MAXV; q += p)
            sieve[q] = p;
    }

    vector<int> pct(MAXV);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int V;
        cin >> V;

        while (V > 1) {
            int lp = sieve[V];
            int ct = 0;

            while (V % lp == 0) {
                V /= lp;
                ct++;
            }

            pct[lp] = max(pct[lp], ct);
        }
    }

    while (K > 1) {
        int lp = sieve[K];
        int ct = 0;

        while (K % lp == 0) {
            K /= lp;
            ct++;
        }

        if (ct > pct[lp]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}