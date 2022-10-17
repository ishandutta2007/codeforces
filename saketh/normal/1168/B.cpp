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

    string s;
    cin >> s;

    ll ans = 0;
    for (int l = 0; l < s.size(); l++) {
        for (int r = l; r < s.size(); r++) {
            assert(r - l <= 12);
            for (int k = 1; r - 2 * k >= l; k++) {
                if (s[r] == s[r-k] && s[r] == s[r - 2 * k]) {
                    ans += s.size() - r;
                    goto DONE;
                }
            }
        }
DONE:
        continue;
    }

    cout << ans << endl;

    return 0;
}