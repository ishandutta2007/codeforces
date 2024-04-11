#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll buddy_hield(ll v) { if (v < 0) return -v; return v; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const ll MAXV = 1e9;

    ll N, K;
    cin >> N >> K;

    vll want;
    want.push_back(1ll);
    if (K == -1) want.push_back(-1ll);

    if (buddy_hield(K) != 1) {
        while (buddy_hield(want.back()) < N * MAXV)
            want.push_back(want.back() * K);
    }

    WATCHC(want);

    vll vals(N);
    for (int i = 0; i < N; i++)
        cin >> vals[i];

    map<ll, int> pref;
    pref[0] = 1;

    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += vals[i];

        for (ll s : want)
                ans += pref[sum - s];

        pref[sum]++;
    }

    cout << ans << endl;
    return 0;
}