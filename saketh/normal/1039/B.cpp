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

bool query(ll lo, ll hi) {
    cout << lo+1 << " " << hi+1 << endl;
    string res;
    cin >> res;
    return res == "Yes";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    srand(time(NULL));

    ll N, K;
    cin >> N >> K;

    auto norm = [&](ll loc) {
        if (loc < 0) return 0ll;
        if (loc >= N) return N - 1ll;
        return loc;
    };

    ll lo = 0, hi = N - 1;
    while (true) {
        if (hi - lo <= 90) {
            ll guess = lo + (rand() % (hi - lo + 1));
            bool ok = query(guess, guess);
            if (ok) return 0;

            lo = norm(lo - K);
            hi = norm(hi + K);
        } else {
            ll mi = (lo + hi) / 2;
            bool res = query(lo, mi);
            if (res) {
                lo = norm(lo - K);
                hi = norm(mi + K);
            } else {
                lo = norm(mi + 1 - K);
                hi = norm(hi + K);
            }
        }
    }

    return 0;
}