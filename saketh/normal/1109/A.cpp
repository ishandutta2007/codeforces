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

    int N;
    cin >> N;

    vi vals(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
    }

    vi pref(N + 1);
    for (int i = 1; i <= N; i++) {
        pref[i] = pref[i-1] ^ vals[i-1];
    }

    ll ans = 0;
    for (int p = 0; p < 2; p++) {
        vi ct(1 << 20);
        for (int i = p; i <= N; i += 2) {
            ans += ct[pref[i]];
            ct[pref[i]]++;
        }
    }

    cout << ans << endl;
    return 0;
}