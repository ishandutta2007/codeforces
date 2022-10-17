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

mt19937 rng(int(chrono::steady_clock::now().time_since_epoch().count()));

void solve() {
    int N, K;
    cin >> N >> K;

    int ans = INT_MAX, loc = -1;

    vi a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (i >= K) {
            int cand = (a[i] - a[i-K] + 1) / 2;
            if (cand < ans) {
                ans = cand;
                loc = (a[i] + a[i-K]) / 2;
            }
        }
    }
    cout << loc << "\n";
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