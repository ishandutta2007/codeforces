#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vll dmg(10, -1);
    dmg[0] = 0;

    int N;
    cin >> N;
    for (int i = 0, K; i < N; i++) {
        cin >> K;
        vvi spells(4);
        for (int j = 0, c, d; j < K; j++) {
            cin >> c >> d;
            spells[c].push_back(d);
        }
        for (auto& v : spells)
            sort(all(v), greater<int>());

        vll upd = dmg;
        auto play = [&](vi d) {
            sort(all(d), greater<int>());
            ll tot = 0; for (ll v : d) tot += v;
            ll dbl = *max_element(all(d));

            for (int m = d.size(); m < 10; m++)
                if (dmg[m - d.size()] != -1)
                    upd[m] = max(upd[m], dmg[m - d.size()] + tot);
            for (int m = 0; m < d.size(); m++)
                if (dmg[m + 10 - d.size()] != -1)
                    upd[m] = max(upd[m], dmg[m + 10 - d.size()] + tot + dbl);
        };

        // one of anything
        for (int c = 1; c <= 3; c++)
            if (spells[c].size())
                play({ spells[c][0] });

        // two x 1
        if (spells[1].size() >= 2)
            play({ spells[1][0], spells[1][1] });

        // three x 1
        if (spells[1].size() >= 3)
            play({ spells[1][0], spells[1][1], spells[1][2] });

        // 1 and 2
        if (spells[1].size() >= 1 && spells[2].size() >= 1)
            play({ spells[1][0], spells[2][0] });

        dmg = upd;
    }

    cout << *max_element(all(dmg)) << endl;

    return 0;
}