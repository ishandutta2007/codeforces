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
    int K;
    cin >> K;

    int tot = 0;
    vi avail(7);
    for (int i = 0; i < 7; i++) {
        cin >> avail[i];
        tot += avail[i];
    }

    assert(tot > 0);

    int weeks = max(0, (K - tot) / tot);
    int days = 14;
    for (int i = 0; i < 7; i++) {
        int j = i, add = 0;
        while (tot * weeks + add < K) {
            add += avail[j % 7];
            j++;
        }
        days = min(days, j - i);
    }

    cout << 7 * weeks + days << "\n";
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