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

    const int MAXV = 1e5 + 1;

    int N;
    cin >> N;

    int ans = 0;
    set<pair<int, int>> ct;

    vi colors(N);
    vi colct(MAXV);
    for (int i = 0; i < N; i++) {
        cin >> colors[i];
        ct.erase({ colct[colors[i]], colors[i] });
        ct.insert({ ++colct[colors[i]], colors[i] });

        bool ok = false;

        if (ct.size() == 1) ok = true;
        else {
            if (ct.begin()->first == 1 &&
                    next(ct.begin())->first == ct.rbegin()->first)
                ok = true;

            if (ct.rbegin()->first == ct.begin()->first + 1 &&
                    next(ct.rbegin())->first == ct.begin()->first)
                ok = true;
        }

        if (ok) ans = max(ans, i + 1);
    }

    cout << ans << endl;

    return 0;
}