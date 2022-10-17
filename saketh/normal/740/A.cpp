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

    ll ans = LLONG_MAX;

    ll N, A, B, C;
    cin >> N >> A >> B >> C;

    for (int b1 = 0; b1 < 4; b1++)
        for (int b2 = 0; b2 < 2; b2++)
            for (int b3 = 0; b3 < 4; b3++) {
                ll have = N + b1 + 2 * b2 + 3 * b3;
                if (have % 4) continue;
                ans = min(ans, b1 * A
                             + b2 * B
                             + b3 * C);
            }

    cout << ans << endl;
    return 0;
}