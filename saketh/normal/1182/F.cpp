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

int MOD;
int sum(int a, int b) { return (ll(a) + b) % MOD; }
int prod(int a, int b) { return (ll(a) * b) % MOD; }

void solve() {
    int A, B, P, Q;
    cin >> A >> B >> P >> Q;

    MOD = 2 * Q;

    const int M = ceil(sqrt(B - A));

    vector<pair<int, int>> baby, uniq;
    for (int i = 0; i < M; i++) {
        baby.emplace_back(prod(2 * i, P), i);
    }
    sort(all(baby));

    for (auto p : baby) if (uniq.empty() || p.first != uniq.back().first) {
        uniq.push_back(p);
    }
    swap(baby, uniq);

    auto find = [&](int v) {
        vector<pair<int, int>> cd = {{ INT_MAX, -1 }};
        for (int tg : { Q - v, 3 * Q - v }) {
            int tr = lower_bound(all(baby), make_pair(tg, -1)) - baby.begin();
            if (tr) cd.emplace_back(abs(sum(baby[tr - 1].first, v) - Q), baby[tr - 1].second);
            if (tr < sz(baby)) cd.emplace_back(abs(sum(baby[tr].first, v) - Q), baby[tr].second);
        }
        sort(all(cd)); return cd.front();
    };

    int md = INT_MAX, ans = -1;

    int v = A;
    for (; v + M < B; v += M) {
        int d, u; tie(d, u) = find(prod(2 * v, P));
        if (d < md) { md = d; ans = v + u; }
    }
    for (; v <= B; v++) {
        if (int d = abs(prod(2 * v, P) - Q); d < md) {
            md = d;
            ans = v;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
        solve();

    return 0;
}