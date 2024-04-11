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
using vb = vector<bool>;
using vs = vector<string>;

void solve() {
    int N; ll K;
    cin >> N >> K;

    vll max_splits(2);
    max_splits[0] = 0;
    max_splits[1] = 1;
    while (max_splits[max_splits.size() - 2] < 1e18) {
        max_splits.push_back(4 * max_splits.back() + 1);
    }

    if (N > max_splits.size()) {
        cout << "YES " << N - 1 << "\n";
        return;
    }

    ll splits = 0, path = 1;
    for (int S = N-1; S >= 0; S--) {
        splits += path;
        path = 2 * path + 1;
        ll limit = max_splits[N] - path * max_splits[S];

        if (splits <= K && K <= limit) {
            cout << "YES " << S << "\n";
            return;
        }
    }

    cout << "NO\n";
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