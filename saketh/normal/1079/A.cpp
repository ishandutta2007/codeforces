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

    int N, U, v;
    cin >> N >> U;

    int mx = 0;
    vi ct(101);

    for (int i = 0; i < N; i++) {
        cin >> v;
        ct[v]++;
        mx = max(mx, ct[v]);
    }

    int tot = (mx + U - 1) / U * U;

    int ans = 0;
    for (int v : ct) {
        if (v) {
            ans += tot - v;
        }
    }

    cout << ans << endl;

    return 0;
}