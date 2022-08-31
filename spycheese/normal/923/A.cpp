#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define FILE "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stdout)
#else
#define eprintf(args...) ;
#endif

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MAXN = (int)1e6 + 100;

int n;
int lp[MAXN];
bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    return 1;
}

int solve(int n, int it) {
    vi primes;
    int x = n;
    int lowest = n;
    while (x > 1) {
        int p = lp[x];
        int k = n / p;
        lowest = min(lowest, p * (k - 1));
        while (x > 1 && x % p == 0) {
            x /= p;
        }
    }

    lowest++;
    lowest = max(lowest, 3);

    if (it == 1) {
        return lowest;
    }

    int ans = n;
    for (int i = lowest; i <= n; i++) {
        if (lp[i] != i) ans = min(ans, solve(i, it + 1));
    }
    return ans;
}

void precalc() {
    memset(lp, -1, sizeof(lp));
    for (int i = 2; i < MAXN; i++) {
        if (lp[i] == -1) {
            for (int j = i; j < MAXN; j += i) {
                lp[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    precalc();

#ifdef LOCAL
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif

    while (read()) {
        cout << solve(n, 0) << '\n';
    }

#ifdef LOCAL
    eprintf("Time %.5f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
}