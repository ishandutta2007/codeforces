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
using vb = vector<bool>;
using vs = vector<string>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    map<int, int> items;
    for (int i = 0; i < N; i++) {
        int subj;
        cin >> subj;
        items[subj]++;
    }

    vi vals;
    for (auto [k, v] : items) {
        vals.push_back(v);
    }
    sort(all(vals));

    ll ans = 0;
    for (int fv = 1; fv <= N; fv++) {
        ll tot = 0;
        auto avail = vals.begin();
        for (ll add = fv; ; add *= 2) {
            auto use = lower_bound(avail, vals.end(), add);
            if (use == vals.end()) break;
            tot += add;
            avail = next(use);
        }
        ans = max(ans, tot);
    }
    cout << ans << endl;

    return 0;
}