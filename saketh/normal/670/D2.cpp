#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N; ll K;
    cin >> N >> K;

    vll need(N), have(N);

    for (int i = 0; i < N; i++)
        cin >> need[i];

    for (int i = 0; i < N; i++)
        cin >> have[i];

    int ans = 0;
    ll lo = 1, hi = 2e9;

    while (lo <= hi) {
        ll mi = (lo + hi) / 2;

        ll ext = 0;
        for (int i = 0; i < N; i++) {
            ll tot = need[i] * mi;
            if (tot > have[i]) {
                if (tot - have[i] > K) {
                    ext = K + 1;
                    break;
                }

                ext += tot - have[i];
                if (ext > K) break;
            }
        }

        if (ext <= K) {
            ans = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    cout << ans << endl;
    return 0;
}