#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

ll ways[16][2][64][1024];

ll get_ways(int base, int digs, int par, bool lead) {
    ll &res = ways[base][lead][digs][par];
    if (res != -1) return res;

    if (digs == 0) {
        return res = int(par == 0);
    }

    res = 0;
    for (int fd = lead; fd < base; fd++) {
        res += get_ways(base, digs - 1, par ^ (1 << fd), false);
    }

    return res;
}

ll solve(ll base, ll lim) {
    if (lim == 0) return 0;

    WATCH(base);
    WATCH(lim);

    vector<int> digs;
    while (lim) {
        digs.push_back(lim % base);
        lim /= base;
    }

    reverse(all(digs));

    WATCHC(digs);

    ll ans = 0;
    for (int len = 1; len < digs.size(); len++) {
        ans += get_ways(base, len, 0, true);
    }

    WATCH(ans);

    int par = 0;
    for (int agree = 0; agree <= digs.size(); agree++) {
        if (agree) par ^= 1 << digs[agree - 1];

        if (agree < digs.size()) {
            for (int nd = !agree; nd < digs[agree]; nd++) {
                ans += get_ways(base, digs.size() - agree - 1, par ^ (1 << nd), false);
            }
        } else {
            ans += get_ways(base, 0, par, false);
        }

        WATCH(agree);
        WATCH(ans);
    }

    WATCH(ans);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    memset(ways, 0xff, sizeof(ways));

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int base;
        ll L, R;

        cin >> base >> L >> R;
        cout << solve(base, R) - solve(base, L - 1) << "\n";
    }

    return 0;
}