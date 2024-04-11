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

int divide(const auto& intv) {
    vector<array<int, 2>> ev;
    for (const auto& e : intv) {
        ev.push_back({ e[0], -1 });
        ev.push_back({ e[1] - 1, 1 });
    }
    sort(all(ev));

    int active = 0;
    for (int i = 0; i < sz(ev); i++) {
        active += ev[i][1];
        if (i+1 < sz(ev) && ev[i][0] == ev[i+1][0]) continue;
        if (i+1 < sz(ev) && active == 0)
            return ev[i][0] + 1;
    }

    return -1;
}

bool split(const auto& castles) {
    assert(sz(castles));
    if (sz(castles) == 1) return true;

    for (int dir = 0; dir < 2; dir++) {
        vector<array<int, 2>> ranges;
        for (const auto& c : castles) {
            ranges.push_back({ c[0 + dir], c[2 + dir] });
        }

        if (int b = divide(ranges); b != -1) {
            vector<array<int, 4>> bef, aft;
            for (const auto& c : castles) {
                if (c[2 + dir] <= b) bef.push_back(c);
                else aft.push_back(c);
            }
            return split(bef) && split(aft);
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vector<array<int, 4>> castle(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++)
            cin >> castle[i][j];
    }

    cout << (split(castle) ? "YES" : "NO") << endl;

    return 0;
}