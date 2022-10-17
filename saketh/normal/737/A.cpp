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

    int C, G, L, T;
    cin >> C >> G >> L >> T;

    // maximum speed is 1 km in 1 mi
    if (T < L) {
        cout << -1 << "\n";
        return 0;
    }

    vi price(C), tank(C);

    for (int i = 0; i < C; i++)
        cin >> price[i] >> tank[i];

    vi gas(G);
    for (int i = 0; i < G; i++)
        cin >> gas[i];

    sort(all(gas));
    gas.push_back(L);

    // maximum tank size is 2 * length, amount need to speed whole way
    int lo = 1, hi = 2 * L;
    int res = hi;

    while (lo <= hi) {
        int mi = (hi - lo) / 2 + lo;

        bool ok = true;
        int time = 0;
        int loc = 0;

        for (int g : gas) {
            int dist = g - loc;
            if (dist > mi) {
                ok = false;
                break;
            }
            else {
                int spend = 2 * dist - min(dist, mi - dist);
                time += spend;
                loc = g;
            }
        }

        if (ok && time <= T) {
            res = mi;
            hi = mi - 1;
        } else lo = mi + 1;
    }

    int low = INT_MAX;

    for (int i = 0; i < C; i++) {
        if (tank[i] >= res)
            low = min(low, price[i]);
    }

    if (low == INT_MAX) cout << -1 << "\n";
    else cout << low << endl;

    return 0;
}