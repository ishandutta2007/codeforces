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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const int MAXV = 1e5 + 100;

    vi sieve(MAXV);
    for (int p = 2; p < MAXV; p++) {
        if (sieve[p]) continue;
        for (int q = p; q < MAXV; q += p)
            sieve[q] = p;
    }

    int N;
    cin >> N;

    vi ct(MAXV);

    vi vals(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
        for (int tmp = vals[i]; tmp > 1; ) {
            int prime = sieve[tmp];
            ct[prime]++;
            while (tmp % prime == 0) tmp /= prime;
        }
    }

    int ans = 1;
    for (int v : ct) ans = max(ans, v);
    cout << ans << endl;

    return 0;
}