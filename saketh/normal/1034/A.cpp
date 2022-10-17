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

    const int MAXV = 1.51e7;
    vi sieve(MAXV);
    for (int p = 2; p < MAXV; p++) {
        if (sieve[p]) continue;
        for (int q = p; q < MAXV; q += p)
            sieve[q] = p;
    }

    vi ct(MAXV);
    int N, v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> v;
        while (v > 1) {
            int p = sieve[v];
            int rep = 0;
            while (v % p == 0) {
                v /= p;
                rep++;
            }
            for (int d = 1, pp = p; d <= rep; d++, pp *= p) {
                ct[pp]++;
            }
        }
    }

    int ans = N;
    for (int g = 2; g < MAXV; g++) {
        int m = ct[g];
        if (m > 0 && m < N)
            ans = min(ans, N - m);
    }
    cout << (ans < N ? ans : -1) << endl;

    return 0;
}