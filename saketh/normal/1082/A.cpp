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
    int N, X, Y, D;
    cin >> N >> X >> Y >> D;

    int ans = INT_MAX;

    if (abs(X - Y) % D == 0) {
        ans = min(ans, abs(X - Y) / D);
    }

    for (int end : { 1, N }) {
        if (abs(end - Y) % D == 0) {
            ans = min(ans, abs(end - Y) / D + (abs(end - X) + D - 1) / D);
        }
    }

    cout << (ans < INT_MAX ? ans : -1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}