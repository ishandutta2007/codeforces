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

ll nc2(ll n) {
    return n * (n - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const double PI = 2 * atan2(1, 0);

    int N;
    cin >> N;
    vi x(N), y(N);
    for (int i = 0; i < N; i++)
        cin >> x[i] >> y[i];

    ll ans = 0;
    for (int o = 0; o < N; o++) {
        int above = 0;
        vector<pair<double, bool>> events;
        for (int i = 0; i < N; i++) {
            if (o == i) continue;
            double a = atan2(y[i] - y[o], x[i] - x[o]);
            if (a < 0) a += 2 * PI;
            if (a + 1e-11 >= PI) {
                events.emplace_back(a - PI, true);
            } else {
                above++;
                events.emplace_back(a, false);
            }
        }

        sort(all(events));

        for (auto e : events) {
            if (!e.second) above--;
            ans += nc2(above) * nc2(N - 2 - above);
            if (e.second) above++;
        }
    }

    cout << ans/2 << endl;
    return 0;
}