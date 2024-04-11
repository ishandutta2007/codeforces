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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll T, N, A, B, K;
    cin >> T >> N >> A >> B >> K;

    ll lo = 0, hi = T;
    while (lo < hi) {
        ll mi = (lo + hi + 1) / 2;
        if (mi * K <= min(mi, A) * ((N + 1) / 2) + min(mi, B) * (N / 2)) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }

    cout << lo << endl;
    return 0;
}