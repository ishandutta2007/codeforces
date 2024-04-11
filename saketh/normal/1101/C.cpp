#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int N;
    cin >> N;
    vi l(N), r(N), o(N), g(N);

    for (int i = 0; i < N; i++) {
        cin >> l[i] >> r[i];
        o[i] = i;
    }

    sort(all(o), [&](int i, int j) {
        return l[i] < l[j];
    });

    int ep = r[o[0]], inx = 1;
    while (inx < N && l[o[inx]] <= ep) {
        ep = max(ep, r[o[inx]]);
        inx++;
    }

    if (inx == N) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < inx; i++)
            g[o[i]] = 1;
        for (int i = 0; i < N; i++)
            cout << g[i] + 1 << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}