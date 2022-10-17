#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, L, V1, V2, K;
    cin >> N >> L >> V1 >> V2 >> K;

    if (V1 >= V2) {
        // just walk
        cout << double(L) / V1 << "\n";
        return 0;
    }

    int groups = (N + K - 1) / K;

    double lo = 0, hi = 1e9;

    for (int i = 0; i < 200; i++) {
        double mi = (lo + hi) / 2;
        double space = mi * groups * V2 - (groups - 1) * (mi * (V2 - V1) * V2 / (V1 + V2));

        if (space > L) {
            hi = mi;
        } else {
            lo = mi;
        }
    }

    cout << lo + (L - lo * V2) / V1 << "\n";
    return 0;
}