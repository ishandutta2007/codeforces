#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll B;
    cin >> B;

    vi pct;
    for (ll p = 2; p * p <= B; p++) {
        if (B % p == 0) {
            int ct = 0;
            while (B % p == 0) {
                ct++;
                B /= p;
            }
            pct.push_back(ct);
        }
    }

    if (B > 1) {
        pct.push_back(1);
    }

    int ans = 1;
    for (int v : pct)
        ans *= v + 1;
    cout << ans << endl;

    return 0;
}