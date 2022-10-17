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

    vector<vector<array<ll, 2>>> ranges(49);
    for (int x = 0; x < 49; x++) {
        for (int v = 0; v < 49; v++) {
            if (x + v > N) continue;
            ll rmin =  1ll*(N - x - v) + 10*x + 5*v;
            ll rmax = 50ll*(N - x - v) + 10*x + 5*v;
            ranges[rmin % 49].push_back( { rmin, rmax } );
        }
    }

    ll ans = 0;
    for (int i = 0; i < 49; i++) {
        sort(all(ranges[i]));
        ll last = LLONG_MIN;
        for (auto p : ranges[i]) {
            ll rmin = max((ll) p[0], last + 49);
            ll rmax = p[1];
            if (rmin <= rmax) {
                ans += 1 + (rmax - rmin)/49;
                last = rmax;
            }
        }
    }
    cout << ans << endl;

    return 0;
}