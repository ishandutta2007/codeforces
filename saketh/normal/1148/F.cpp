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

    vll val(N), mask(N);
    ll tot = 0;

    for (int i = 0; i < N; i++) {
        cin >> val[i] >> mask[i];
        tot += val[i];
    }

    ll res = 0;
    for (int b = 0; b < 62; b++) {
        ll cur = 0;
        for (int i = 0; i < N; i++) {
            if ((mask[i] & (1ll << b)) && (mask[i] < (1ll << (b+1))))
                cur += val[i];
        }

        if ((cur > 0 && tot > 0) || (cur < 0 && tot < 0)) {
            res ^= 1ll << b;
            for (int i = 0; i < N; i++) {
                if (mask[i] & (1ll << b))
                    val[i] *= -1;
            }
        }
    }

    cout << res << endl;

    return 0;
}