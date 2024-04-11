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

ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

array<ll, 2> mend(ll prev, ll X, ll Y, ll K) {
    array<ll, 2> res = { LLONG_MAX, LLONG_MAX };
    if (prev == LLONG_MAX) return res;

    ll amin = ceil(prev + X, K);
    ll amax = 1 + X;

    ll bmin = ceil(Y, K);
    ll bmax = Y;

    // case 1: end with the same character as before.. as = bs + 1
    {
        ll cmin = max(amin, bmin + 1);
        ll cmax = min(amax, bmax + 1);
        if (cmin <= cmax) {
            res[0] = max(1ll, prev + X - K * (cmax - 1));
        }
    }

    // case 2: end with the other character... as = bs
    {
        ll cmin = max(amin, bmin);
        ll cmax = min(amax, bmax);
        if (cmin <= cmax) {
            res[1] = max(1ll, Y - K * (cmax - 1));
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;
    vi x(N), y(N);
    for (int i = 0; i < N; i++)
        cin >> x[i];
    for (int i = 0; i < N; i++)
        cin >> y[i];

    ll a = 0, b = 0;
    for (int i = 0; i < N; i++) {
        ll as = LLONG_MAX, bs = LLONG_MAX;

        auto r1 = mend(a, x[i], y[i], K);
        as = min(as, r1[0]);
        bs = min(bs, r1[1]);

        auto r2 = mend(b, y[i], x[i], K);
        bs = min(bs, r2[0]);
        as = min(as, r2[1]);

        a = as;
        b = bs;
    }

    if (a < LLONG_MAX || b < LLONG_MAX) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}