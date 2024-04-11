#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll N;
    cin >> N;

    vi vals(N);
    for (int i = 0; i < N; i++)
        cin >> vals[i];

    ll ans = 0;

    ll m0 = 0, m1 = 0;
    ll s0 = 0, s1 = 0;

    for (int i = 0; i < N - 1; i++) {
        ll diff = llabs(vals[i + 1] - vals[i]);
        if (i & 1) {
            s0 -= diff;
            s1 += diff;
        } else {
            s0 += diff;
            s1 -= diff;
        }

        ans = max(ans, s0 - m0);
        ans = max(ans, s1 - m1);

        m0 = min(m0, s0);
        m1 = min(m1, s1);
    }

    cout << ans << endl;
    return 0;
}